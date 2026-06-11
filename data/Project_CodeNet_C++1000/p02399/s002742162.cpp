#include<iostream>
#include<stdio.h>

int main()
{
	int a, b;
	std::cin >> a >> b;
	int d, r;
	double f;
	d = a / b;
	r = a % b;
	f = (double)a / (double)b;
	printf("%d %d %.8lf\n", d, r, f);

	return 0;
}