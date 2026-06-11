#include <cmath>
#include <cstdio>
int a, b, c; double d, s, l, f, h, t;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	d = 1.0 * c / 180.0 * 3.14159265358979;
	h = b * sin(d);
	f = sqrt(b * b - h * h);
	t = a + (c > 90 ? 1.0 : -1.0) * f;
	s = a * h / 2.0;
	l = a + b + sqrt(t * t + h * h);
	printf("%.9f\n", s);
	printf("%.9f\n", l);
	printf("%.9f\n", h);
	return 0;
}