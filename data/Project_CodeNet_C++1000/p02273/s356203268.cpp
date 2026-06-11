#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
using namespace std;

struct point {
	double x, y;
};
void koch(int d, point p1, point p2) {
	if (d == 0) return;
	point s, t, u;
	double pi = acos(-1);
	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 3;
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	u.x = s.x + (t.x - s.x) * cos(pi / 3) - (t.y - s.y) * sin(pi / 3);
	u.y = s.y + (t.y - s.y) * cos(pi / 3) + (t.x - s.x) * sin(pi / 3);
	koch(d - 1, p1, s);
	printf("%.4f %.4f\n", s.x, s.y);
	koch(d - 1, s, u);
	printf("%.4f %.4f\n", u.x, u.y);
	koch(d - 1, u, t);
	printf("%.4f %.4f\n", t.x, t.y);
	koch(d - 1, t, p2);
}

int main() {
	int n;
	cin >> n;
	point p1, p2;
	p1.x = 0, p1.y = 0, p2.x = 100, p2.y = 0;
	printf("%.4f %.4f\n", p1.x, p1.y);
	koch(n, p1, p2);
	printf("%.4f %.4f\n", p2.x, p2.y);
}
