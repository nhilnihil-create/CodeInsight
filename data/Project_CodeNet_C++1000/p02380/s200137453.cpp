#define  _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	a *= 1.0;
	b *= 1.0;
	double angle = sinl(1.0*c*2*M_PI/360.0);
	double S, L, h;
	S = 0.5*a*b*angle;
	L = a + b + sqrt(powl(a, 2) + powl(b, 2) - 2 * a*b*cosl(1.0*c*2*M_PI/360.0));
	h = 2 * S / a;
	printf("%lf\n", S);
	printf("%lf\n", L);
	printf("%lf\n", h);
}