#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <functional>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

struct point
{
	double x;
	double y;
};

void koch(int d, point p1, point p2)
{
	if (d == 0)
	{
		return;
	}
	double th = M_PI * 60.0 / 180.0;
	point s, t, u;
	s.x = (2.0 * p1.x + p2.x) / 3.0;
	s.y = (2.0 * p1.y + p2.y) / 3.0;
	t.x = (p1.x + 2.0 * p2.x) / 3.0;
	t.y = (p1.y + 2.0 * p2.y) / 3.0;
	u.x = s.x + (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th);
	u.y = s.y + (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th);
	koch(d - 1, p1, s);
	printf("%.8f %.8f\n", s.x, s.y);
	koch(d - 1, s, u);
	printf("%.8f %.8f\n", u.x, u.y);
	koch(d - 1, u, t);
	printf("%.8f %.8f\n", t.x, t.y);
	koch(d - 1, t, p2);
}


void solve()
{
	int n;
	cin >> n;
	point p1, p2;
	p1.x = 0.0;
	p1.y = 0.0;
	p2.x = 100.0;
	p2.y = 0.0;
	printf("%.8f %.8f\n", p1.x, p1.y);
	koch(n, p1, p2);
	printf("%.8f %.8f\n", p2.x, p2.y);
}

int main()
{
	solve();
	return(0);
}