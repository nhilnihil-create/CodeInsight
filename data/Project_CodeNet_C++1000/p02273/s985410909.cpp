#include<cstdio>
#include<cmath>
#define PI acos(-1)
#define scanf_s scanf
struct Point {
	double x, y;
};
void koch(int n, Point a, Point b) {
	if (n == 0)return;
	Point s, t, u;
	double rad = PI * 60.0 / 180.0;
	s.x = (2.0*a.x + 1.0*b.x) / 3.0;
	s.y = (2.0*a.y + 1.0*b.y) / 3.0;
	t.x = (1.0*a.x + 2.0*b.x) / 3.0;
	t.y = (1.0*a.y + 2.0*b.y) / 3.0;
	u.x = (t.x - s.x)*cos(rad) - (t.y - s.y)*sin(rad) + s.x;
	u.y = (t.x - s.x)*sin(rad) + (t.y - s.y)*cos(rad) + s.y;
	koch(n - 1, a, s);
	printf("%.8f %.8f\n", s.x, s.y);
	koch(n - 1, s, u);
	printf("%.8f %.8f\n", u.x, u.y);
	koch(n - 1, u, t);
	printf("%.8f %.8f\n", t.x, t.y);
	koch(n - 1, t, b);
}
int main() {
	int n; scanf_s("%d", &n);
	Point a, b;
	a.x = 0; a.y = 0; b.x = 100; b.y = 0;
	printf("%.8f %.8f\n", a.x, a.y);
	koch(n, a, b);
	printf("%.8f %.8f\n", b.x, b.y);
	return 0;
}