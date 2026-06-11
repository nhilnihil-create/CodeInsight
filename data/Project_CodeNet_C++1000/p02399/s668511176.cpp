#include<stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d %d %f\n", a / b, a % b, (a*1.00) / (b*1.00));
	return 0;
}