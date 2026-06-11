#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

const double PI = 3.14159265;
typedef struct {
	double x, y;
}point;

void koch(int d, point &p1, point &p2)
{
	if (d == 0)
		return;
	point s, u, t;
	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 3;
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	u.x = (t.x - s.x) * cos(60 * PI / 180.0) - (t.y - s.y) * sin(60 * PI / 180.0) + s.x;
	u.y = (t.x - s.x) * sin(60 * PI / 180.0) + (t.y - s.y) * cos(60 * PI / 180.0) + s.y;
	koch(d - 1, p1, s);
	printf("%.8lf %.8lf\n", s.x, s.y);
	koch(d - 1, s, u);
	printf("%.8lf %.8lf\n", u.x, u.y);
	koch(d - 1, u, t);
	printf("%.8lf %.8lf\n", t.x, t.y);
	koch(d - 1, t, p2);
}
int main(void)
{
	int n;
	cin >> n;
	point p1 = { 0,0 }, p2 = { 100,0 };
	printf("%.8lf %.8lf\n", p1.x, p1.y);
	koch(n, p1, p2);
	printf("%.8lf %.8lf\n", p2.x, p2.y);
	return 0;
}
