#include<stdio.h>
int main() 
{
	int a,b,d,r;
	double f;
	scanf("%d %d", &a, &b);
	d = a / b;
	r = a % b;
	f = a * 1.00000 / b * 1.00000;
	printf("%d %d %f", d, r, f);
	return 0;
}