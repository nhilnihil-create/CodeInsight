#include<stdio.h>

int main()
{
	double a, b, c;
	
    scanf("%lf%lf", &a, &b);

	printf("%d ", (int)a/(int)b);
	printf("%d ", (int)a % (int)b);
	printf("%lf\n", a / b);

	return 0;
}