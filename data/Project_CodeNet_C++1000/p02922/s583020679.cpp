#include<stdio.h>

int main(){
    int a, b, ans=1,i=0;
    scanf("%d %d", &a, &b);
    while(ans<b){
        ans=ans-1+a;
        i++;
    }
    printf("%d",i);
    return 0;
}