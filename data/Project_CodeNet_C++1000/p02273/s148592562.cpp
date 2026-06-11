#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

const double Sixty = M_PI*60.0 / 180.0;

struct Point
{
	double x, y;
public:
	Point() { x = y = 0; }
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void print() { printf("%.8f %.8f\n", x, y); }
};

void getPoint_div3(Point &r, Point a, Point b)
{
	r.x = ((a.x * 2.0) + b.x) / 3.0;
	r.y = ((a.y * 2.0) + b.y) / 3.0;
}

void getPoint_top(Point &r, Point a, Point b)
{
	double dx = b.x - a.x;
	double dy = b.y - a.y;

	r.x = cos(Sixty)*dx - sin(Sixty)*dy + a.x;
	r.y = sin(Sixty)*dx + cos(Sixty)*dy + a.y;
}

void koch(int d, Point a, Point b)
{
	if (!d) return;

	Point s, t, u;
	getPoint_div3(s, a, b);
	getPoint_div3(t, b, a);
	getPoint_top(u, s, t);

	koch(d - 1, a, s);
	s.print();
	koch(d - 1, s, u);
	u.print();
	koch(d - 1, u, t);
	t.print();
	koch(d - 1, t, b);
}

int main()
{
	Point p1(0.0, 0.0), p2(100.0, 0.0);
	int n;

	scanf("%d", &n);

	p1.print();
	koch(n, p1, p2);
	p2.print();

	return 0;
}