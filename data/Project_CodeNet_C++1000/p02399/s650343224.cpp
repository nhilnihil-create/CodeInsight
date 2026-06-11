#include <stdio.h>
#include<iostream>
int main()
{
	int a, b;
	double f;
	scanf("%d %d", &a, &b);
	f = 1.0000*a / b;
	printf("%d %d %f\n", a / b, a%b, f);
	return 0;
}

