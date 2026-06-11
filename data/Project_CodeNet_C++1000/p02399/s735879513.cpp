#include<stdio.h>

int main(void){

int a,b,d,r;

double f;


scanf("%d %d",&a,&b);

if(1<=a,b<=1E+9){

d=a/b;


r=a%b;


f=(double)a/(double)b;


printf("%d %d %lf\n",d,r,f);

}

return 0;

}