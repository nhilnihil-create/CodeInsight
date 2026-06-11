#include <cstdio>
#include <cmath>

int main()
{
	double pi = 4*atan(1);
	double radius;
	scanf("%lf", &radius);
	printf("%lf %lf", pi*radius*radius, 2*pi*radius);
	return 0;
}