#include<stdio.h>
#define f(i,m) for(int i=1;i<=m;i++)
int main(){
    f(i,9)f(j,9)printf("%dx%d=%d\n",i,j,i*j);
    return 0;
}