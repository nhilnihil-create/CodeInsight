#include <stdio.h>

int main(int argc, char** argv)
{
	double r;
	scanf("%lf", &r);
	const double pi = 3.141592653589793238;
	printf("%lf %lf", pi * r * r, 2 * pi * r);
	return 0;
}
