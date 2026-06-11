#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a=n%1000;
    int b=1000-a;
    printf("%d",b%1000);
    return 0;
}