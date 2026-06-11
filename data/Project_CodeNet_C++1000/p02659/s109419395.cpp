#include<stdio.h>
int main()
{
  	long long int a,s;
	double  b;
	 scanf ("%lld",&a);
	 scanf("%lf",&b);
	s=b*100+0.001;
	s=(a*s)/100;
	 printf("%lld",s);
	 }
