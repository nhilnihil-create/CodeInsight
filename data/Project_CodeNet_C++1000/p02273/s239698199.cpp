#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <list>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int n;

struct Point 
{
	double x, y;
};

void kock(int n, Point p1, Point p2) {
	if (n == 0) return;

	Point s, u, t;
	double sixty = M_PI *60/180;

	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 3;
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	u.x = (t.x - s.x)*cos(sixty) - (t.y - s.y)*sin(sixty) + s.x;
	u.y = (t.x - s.x)*sin(sixty) + (t.y - s.y)*cos(sixty) + s.y;

	kock(n - 1, p1, s);
	printf("%.8f %.8f\n", s.x, s.y);
	kock(n - 1, s, u);
	printf("%.8f %.8f\n", u.x, u.y);
	kock(n - 1, u, t);
	printf("%.8f %.8f\n", t.x, t.y);
	kock(n - 1, t, p2);

}

int main(void) {

	Point a, b;
	a.x = 0;
	a.y = 0;
	b.x = 100;
	b.y = 0;

	cin >> n;

	printf("%.8f %.8f\n", a.x, a.y);
	kock(n, a, b);
	printf("%.8f %.8f\n", b.x, b.y);

	return 0;
}