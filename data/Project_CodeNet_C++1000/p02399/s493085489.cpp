#include<stdio.h>
int main(void){
int a,b,d,r;
double f;
scanf("%d",&a);
scanf("%d",&b);
d=a/b;
r=a%b;
f=(double)a/b;
printf("%d %d %.5lf\n",d,r,f);
return 0;
}