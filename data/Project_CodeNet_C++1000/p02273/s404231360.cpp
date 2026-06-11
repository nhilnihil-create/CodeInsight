#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>

#define myPrint(a, b) printf("%12.8f %12.8f\n", a, b)

struct myPoint { double x, y; };

void koch(int n, myPoint a, myPoint b) {
	myPoint s, t, u;
	double th = M_PI * (60.0 / 180.0);

	if (n == 0) return;
	s.x = (2.0 * a.x + b.x) / 3.0;
	s.y = (2.0 * a.y + b.y) / 3.0;
	t.x = (a.x + 2.0 * b.x) / 3.0;
	t.y = (a.y + 2.0 * b.y) / 3.0;
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.y - s.y) * cos(th) + (t.x - s.x) * sin(th) + s.y;

	koch(n - 1, a, s);
	myPrint(s.x, s.y);
	koch(n - 1, s, u);
	myPrint(u.x, u.y);
	koch(n - 1, u, t);
	myPrint(t.x, t.y);
	koch(n - 1, t, b);
} 

int main() {
	myPoint a, b;
	int n;

	scanf("%d", &n);

	a.x = 0;
	a.y = 0;
	b.x = 100;
	b.y = 0;

	myPrint(a.x, a.y);
	koch(n, a, b);
	myPrint(b.x, b.y);

	return 0;
}