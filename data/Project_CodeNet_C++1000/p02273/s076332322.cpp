#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

class Point
{
public:
	double x;
	double y;
	Point *prev;
	Point *next;
	Point();
	void MakePointS(Point *p1, Point *p2);
	void MakePointT(Point *p1, Point *p2);
	void MakePointU(Point *s, Point *t);
	void Output();
};

void Link(Point *p1, Point *p2)
{
	p1->next = p2;
	p2->prev = p1;
}

Point::Point()
{
	prev = NULL;
	next = NULL;
}

void Point::MakePointS(Point *p1, Point *p2)
{
	x = p1->x + (p2->x - p1->x) / 3;
	y = p1->y + (p2->y - p1->y) / 3;
	Link(p1, this);
}

void Point::MakePointT(Point *p1, Point *p2)
{
	x = p1->x + (p2->x - p1->x) * 2 / 3;
	y = p1->y + (p2->y - p1->y) * 2 / 3;
	Link(this, p2);
}

void Point::MakePointU(Point *s, Point *t)
{
	Point t0;
	t0.x = t->x - s->x;
	t0.y = t->y - s->y;
	Point t1;
	t1.x = t0.x * cos(M_PI / 3) - t0.y * sin(M_PI / 3);
	t1.y = t0.x * sin(M_PI / 3) + t0.y * cos(M_PI / 3);
	x = t1.x + s->x;
	y = t1.y + s->y;
	Link(s, this);
	Link(this, t);
}

void Point::Output()
{
	cout << fixed << x << " " << y << endl;
	if (next) {
		next->Output();
	}
}

void MakeKochCurve(int n, Point *p1, Point *p2)
{
	if (n <= 0) return;
	Point *s = new Point();
	s->MakePointS(p1, p2);
	Point *t = new Point();
	t->MakePointT(p1, p2);	
	Point *u = new Point();
	u->MakePointU(s, t);
	n--;
	MakeKochCurve(n, p1, s);
	MakeKochCurve(n, s, u);
	MakeKochCurve(n, u, t);
	MakeKochCurve(n, t, p2);
}

int main(void)
{
	//input
	int n;
	cin >> n;

	//KochCurve?
	Point p1;
	p1.x = 0;
	p1.y = 0;
	Point p2;
	p2.x = 100;
	p2.y = 0;
	Link(&p1, &p2);
	MakeKochCurve(n, &p1, &p2);

	//output
	p1.Output();

	return 0;
}
