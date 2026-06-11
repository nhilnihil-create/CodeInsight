#include<cstdio>
#include<math.h>

int main(){
	double a, b, c, d;
	scanf("%lf %lf %lf", &a, &b, &c);
	c = M_PI * c / 180;
	d = sqrt(a * a + b * b - 2 * a * b * cos(c));
	printf("%lf\n", a * b * sin(c) / 2);
	printf("%lf\n", a + b + d);
	printf("%lf\n", b * sin(c));
	return 0;
}