#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <math.h>
using namespace std;
const double th = M_PI * 60 / 180;
struct P {
	double x, y;
};
void makeKoch(P a, P b, int de) {
	if (de == 0) return;
	P c, d, e;
	c.x = (a.x * 2 + b.x) / 3;
    c.y = (a.y * 2 + b.y) / 3;
	d.x = (a.x + b.x * 2) / 3;
	d.y = (a.y + b.y * 2) / 3;
	e.x = c.x + (d.x - c.x) * cos(th) - (d.y - c.y) * sin(th);
	e.y = c.y + (d.x - c.x) * sin(th) + (d.y - c.y) * cos(th);
	makeKoch(a, c, de - 1);
	printf("%.8f %.8f\n", c.x, c.y);
	makeKoch(c, e, de - 1);
	printf("%.8f %.8f\n", e.x, e.y);
	makeKoch(e, d, de - 1);
	printf("%.8f %.8f\n", d.x, d.y);
	makeKoch(d, b, de - 1);

}
int main() {
	P p0, p1;
	p0.x = 0;
	p0.y = 0;
	p1.x = 100;
	p1.y = 0;
	int n;
	scanf("%d", &n);
	printf("%.8f %.8f\n", p0.x, p0.y);
    makeKoch(p0, p1, n);
	printf("%.8f %.8f\n", p1.x, p1.y);
	return 0;

}