#include <stdio.h>
int main(){
    int W,H,x,y,r;
    scanf("%d %d %d %d %d",&W,&H,&x,&y,&r);
    int ue,shita,migi,hidari;
    ue = y+r;
    shita = y-r;
    migi = x + r;
    hidari = x - r;
    if(H < ue || shita < 0 || H < migi || hidari < 0 ){
        printf("No\n");
    }else{
        printf("Yes\n");
    }   
}