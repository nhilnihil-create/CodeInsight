#include <stdio.h>

int main(void)
{
	double r,pi;

	pi = 3.14159265358979323846;

	scanf("%lf", &r);

	printf("%.6lf %.6lf\n", r*r*pi, r*2*pi);


	getchar();
	return 0;
}