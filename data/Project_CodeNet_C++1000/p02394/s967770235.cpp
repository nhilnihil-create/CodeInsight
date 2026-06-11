#include<stdio.h>
int main(){
    int w,h,x,y,r;
    int isout=1;
    scanf("%d%d%d%d%d",&w,&h,&x,&y,&r);
    if((x-r)<0||(y-r)<0||(x+r)>w||(y+r)>h){
    }else{
        isout=0;
    }
    printf("%s\n",isout?"No":"Yes");
    return 0;
}