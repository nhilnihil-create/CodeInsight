#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define th 3.141592653589793/3

struct point {
	double x, y;
};

void print(point p) {
	cout << fixed << setprecision(8) << p.x << " " << p.y << endl;
}

void koch(int d, point p1, point p2) {
	if (d == 0)
		return;
	point s, u, t;
	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 3;
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
	koch(d - 1, p1, s);
	print(s);
	koch(d - 1, s, u);
	print(u);
	koch(d - 1, u, t);
	print(t);
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
	print(a);
	koch(n, a, b);
	print(b);
	return 0;
}

