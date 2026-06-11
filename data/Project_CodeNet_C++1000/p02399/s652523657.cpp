#include<stdio.h>

int main(void)
{

int a,b;
int d,r;
double f;

scanf("%d",&a);
scanf("%d",&b);

d=a/b;
r=a%b;
f=(double)a/(double)b;

printf("%d %d %f\n",d,r,f);

return 0;
}