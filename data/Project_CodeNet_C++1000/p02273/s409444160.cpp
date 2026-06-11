#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

struct Point { 
	double x, y;
};

void koth(int n, Point s1, Point s2) {
	if ( n == 0 ) return;
	Point s, u, t;
	double th = M_PI * 60.0 / 180.0;

	s.x = (2.0 * s1.x + 1.0 * s2.x) / 3.0;
	s.y = (2.0 * s1.y + 1.0 * s2.y) / 3.0;
	t.x = (1.0 * s1.x + 2.0 * s2.x) / 3.0;
	t.y = (1.0 * s1.y + 2.0 * s2.y) / 3.0;
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

	koth(n - 1, s1, s);
	printf("%.8f %.8f\n", s.x, s.y);
	koth(n - 1, s, u);
	printf("%.8f %.8f\n", u.x, u.y);
	koth(n - 1, u, t);
	printf("%.8f %.8f\n", t.x, t.y);
	koth(n - 1, t, s2);
	return;
}


int main() {
	Point a, b;
	int n;

	scanf("%d", &n);
	a.x = 0;
	a.y = 0;
	b.x = 100.0;
	b.y = 0;
	printf("%.8f %.8f\n", a.x, a.y);
	koth(n, a, b);
	printf("%.8f %.8f\n", b.x, b.y);

	return 0;
}

