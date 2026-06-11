#include<stdio.h>
int main(void)
{
	double r, x, y;
	scanf("%lf", &r);
	x=(double)r*(double)r*3.141592653589;
	y=((double)r+(double)r)*3.141592653589;
	printf("%f %f\n", x, y);
	return 0;
}
