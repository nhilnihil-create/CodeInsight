#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <list>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

struct point{ double x; double y; };

void Koch(point a, point b, int n) {
	if(n == 0) return;
	point s, t, u;
	double th = M_PI * 60.0 / 180.0; 

	s.x = (2.0*a.x + b.x)/3.0;
	s.y = (2.0*a.y + b.y)/3.0;
	t.x = (a.x + 2.0*b.x) / 3.0;
	t.y = (a.y + 2.0*b.y) / 3.0;
	u.x = (t.x-s.x) * cos(th) - (t.y-s.y) * sin(th) + s.x;
	u.y = (t.x-s.x) * sin(th) + (t.y-s.y) * cos(th) + s.y;

	Koch(a, s, n-1);
	printf("%.8f %.8f\n", s.x, s.y);
	Koch(s, u, n-1);
	printf("%.8f %.8f\n", u.x, u.y);
	Koch(u, t, n-1);
	printf("%.8f %.8f\n", t.x, t.y);
	Koch(t, b, n-1);
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
	Koch(a, b, n);
	printf("%.8f %.8f\n", b.x, b.y);
	return 0;
}