#include<stdio.h>
int main()
{
	int d,r;
	int a,b;
	scanf("%d%d",&a,&b);
	d = a / b;
	r = a % b;
	printf("%d %d", d, r);
	double x, y;
	double  f;
	x = a;
	y = b;
	f = x / y;
	printf(" %f\n", f);
	return 0;
}