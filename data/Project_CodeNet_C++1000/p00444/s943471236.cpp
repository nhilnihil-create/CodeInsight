#include<cstdio>
#include<iostream>
int main(){
    while(1){
        int x;
        int coin,n=0;
        scanf("%d",&x);
        if(x==0)
            break;
        x=1000-x;
        for(int i=0;i<6;i++){
            if(i==0)
                coin=500;
            else if(i==1)
                coin=100;
            else if(i==2)
                coin=50;
            else if(i==3)
                coin=10;
            else if(i==4)
                coin=5;
            else
                coin=1;
            for(;x>=coin;){
                x-=coin;
                n++;
            }
        }
        printf("%d\n",n);
    }
    return 0;
}