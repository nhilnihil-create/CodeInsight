#include<stdio.h>
#include<math.h>

int main()
{
	double x1, y1, x2, y2;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	x1 *= 1.0;
	x2 *= 1.0;
	y1 *= 1.0;
	y2 *= 1.0;
	printf("%lf\n", sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}