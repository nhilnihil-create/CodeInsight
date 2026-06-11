#include<stdio.h>
int main(){
    int x;
    int tmp;
    for(int i=1;i<=5;i++){
        scanf("%d",&tmp);
        if(tmp==0) x=i;
    }
    printf("%d",x);
    return 0;
}