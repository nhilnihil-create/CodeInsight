#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
};

void koch(int d,point p1, point p2) {
	if (d == 0) {
		return;
	}
	point s, t, u;
	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 3;
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	u.x = (t.x - s.x) / 2 - sqrt(3) / 2 * (t.y - s.y) + s.x;
	u.y = sqrt(3) / 2 * (t.x - s.x) + (t.y - s.y) / 2 + s.y ;
	koch(d - 1, p1, s);
	printf("%.8f %.8f\n", s.x, s.y);
	koch(d - 1, s, u);
	printf("%.8f %.8f\n", u.x, u.y);
	koch(d - 1, u, t);
	printf("%.8f %.8f\n", t.x, t.y);
	koch(d - 1, t, p2);
}

int main() {
	int n;
	cin >> n;
	point a, b;
	a.x = 0;
	a.y = 0;
	b.x = 100;
	b.y = 0;
	printf("%.8f %.8f\n", a.x, a.y);
	koch(n, a, b);
	printf("%.8f %.8f\n", b.x, b.y);

	return 0;
}
