/*Hello...This is snake game created by Ujjwal Jain.*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
int tailx[100],taily[100],counttail;
int ht=20,wd=20;    // used in creating boundary.
int x,y;    //snake position.
int fruitx,fruity;  //fruit position.
int score,gameover=0;  //score.
int flag;
void setup(){   //Function to setup snake and fruit position. 
    gameover=0;
    x=wd/2;
    y=ht/2;
    label1:
    fruitx=rand()%20;
    if(fruitx==0){
        goto label1;
    }
    label2:
    fruity=rand()%20;
    if(fruity==0){
        goto label2;
    }
    score=0;
}
void draw(){    //Function to create boundary,snake,fruit.
    int i,j,k;
    system("cls");
    for(i=0;i<wd;i++){
        for(j=0;j<ht;j++){
            if(i==0||j==0||i==wd-1||j==ht-1){
                printf("#");    //print boundary.
            }
            else{
                if(i==x && j==y){   //print snake.
                    printf("0");
                }
                else if(i==fruitx && j==fruity){    //print fruit.
                    printf("f");
                }
                else{
                    int ch=0;
                    for(k=0;k<counttail;k++){
                        if(i==tailx[k] && j==taily[k]){
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0){
                        printf(" ");    //print blank space.
                    }
                }
            }
        }
        printf("\n");
    }
    printf("\nYour Score:%d",score);
}
void input(){
    // printf("Press any key:");
    //char c=getch();
    if(kbhit()){    //return non zero value if any key is pressed.
        switch (getch()){
            case 'a':
                flag=1;
                break;
            case 's':
                flag=2;
                break;
            case 'w':
                flag=3;
                break;
            case 'd':
                flag=4;
                break;
            case 'x':
                gameover=1;
                break;
        }
    }
}
void logic(){
    int prevx=tailx[0];
    int prevy=taily[0];
    int i,prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;
    for(i=1;i<counttail;i++){   //shifting snake.
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch (flag)
    {
    case 1:     //to move left decrease y coordinate.
        y--;    
        break;
    case 2:     //to move down increase x coordinate.
        x++;    
        break;
    case 3:     //to move up decrease x coordinate.
        x--;
        break;
    case 4:     //to move right decrease y coordinate.
        y++;
        break;
    default:
        break;
    }
    if(x<=0 || x==wd-1 || y==0 || y==ht-1){
        gameover=1;
    }
    for(i=0;i<counttail;i++){
        if(x==tailx[i] && y==taily[i]){
            gameover=1;
        }
    }
    if(x==fruitx && y==fruity){
        label3:
        fruitx=rand()%20;
        if(fruitx==0){
            goto label3;
        }
        label4:
        fruity=rand()%20;
        if(fruity==0){
            goto label4;
        }
        score+=10;
        counttail++;
    }
}
int main(){
    char c;
    label5:
    setup();
    //Below three functions need to be repeated again and again.
    while(gameover!=1){
        system("color b0");
        draw();
        input();
        logic();
        Sleep(250);
    }
    return 0;
}