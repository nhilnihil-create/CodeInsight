#include <stdio.h>
#include <math.h>
double pi = 3.14159265358979323846;
double l = 0, r = pi / 2, m;
double a, b, x;
double S(double t) {
	if (a * tan(t) < b)return(a * b - 0.5 * a * a * tan(t));
	else return 0.5 * b * b / tan(t);
}
int main() {
	scanf("%lf%lf%lf", &a, &b, &x);
	x /= a;
	while ((l + 0.0000000001) < r) {
		m = (r + l) / 2;
		if (S(m) <= x)r = m;
		else l = m;
	}
	printf("%.10lf\n", r * 180 / pi);
}
