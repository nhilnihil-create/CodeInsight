#include<stdio.h>
#include<math.h>
int main(void)
{
	double a,b,c,d;
	//d=3.14159265;
	scanf("%lf",&a);
	b=a*a*M_PI;
	c=(a+a)*M_PI;
	printf("%lf %lf\n",b,c);
	return 0;
}