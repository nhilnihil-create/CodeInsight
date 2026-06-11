#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

const double PI = 3.1415926535;
const double th = 60 * PI / 180;

class p
{
public:
	double x;
	double y;
	void print();
};

void p::print()
{
	printf("%.8f %.8f\n", x, y);
}

void koch(int d, p p1, p p2)
{
	if (d == 0)return;
	p s, u, t;
	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 3;
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	u.x = (t.x - s.x)*cos(th) - (t.y - s.y)*sin(th) + s.x;
	u.y = (t.x - s.x)*sin(th) + (t.y - s.y)*cos(th) + s.y;
	koch(d - 1, p1, s);
	s.print();
	koch(d - 1, s, u);
	u.print();
	koch(d - 1, u, t);
	t.print();
	koch(d - 1, t, p2);
}

int main()
{
	int d;
	p f, l;
	cin >> d;
	f.x = f.y = l.y = 0;
	l.x = 100;
	f.print();
	koch(d, f, l);
	l.print();
    return 0;
}