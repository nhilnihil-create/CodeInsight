#include<iostream>
#include<cstdio>

int main()
{
	double r;
	std::cin >> r;
	double area, circum;
	double PI = 3.141592653589;
	area = PI * r * r;
	circum = r * 2.0 * PI;
	printf("%.5lf %.5lf\n", area, circum);

	return 0;
}