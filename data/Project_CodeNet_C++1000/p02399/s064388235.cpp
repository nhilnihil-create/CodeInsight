#include <stdio.h>
int main(void)
{
	int a, b, d, r;
	scanf("%d %d", &a, &b);
	double f;
	d=a/b;
	r=a%b;
	f=1.0*a/b;
	printf("%d %d %lf\n", d, r, f);
	
	return 0;
}
