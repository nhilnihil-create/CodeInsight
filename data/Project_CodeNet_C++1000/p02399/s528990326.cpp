#include <stdio.h>

int main (void)
{
	int a,b,d,r;
	double a1,b1,f;

	scanf("%d %d",&a,&b);

	a1 = a;
	b1 = b;
	d = a / b;
	r = a % b;
	f = a1 / b1;

	printf("%d %d %.8f\n",d,r,f);

	return 0;
}