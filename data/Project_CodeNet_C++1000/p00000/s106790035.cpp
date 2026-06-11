#include<stdio.h>
#define F(i) for(i=1;i<=9;i++)
int main(){int i,j;F(i)F(j)printf("%dx%d=%d\n",i,j,i*j);}