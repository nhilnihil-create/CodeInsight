#include<stdio.h>
int a[10000]={1,1};
int kaishi(int n){
    if(a[n])return a[n];
    a[n]=kaishi(n-1)+kaishi(n-2);
    return a[n];
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",kaishi(n));
    return 0;
}