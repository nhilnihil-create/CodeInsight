#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
using namespace std;
using vec = pair<double, double>;


void koch(int d, vec p1, vec p2) {
	if (d == 0) return;

	vec s, u, t;
	double rad = M_PI * 60 / 180. ;

	// cauculate new coordinate
	// first : x, second : y
	s.first  = (p2.first  - p1.first)  / 3 + p1.first;
	s.second = (p2.second - p1.second) / 3 + p1.second;
	t.first  = (p2.first  - p1.first ) / 3 * 2 + p1.first;
	t.second = (p2.second - p1.second) / 3 * 2 + p1.second;
	u.first  = (t.first - s.first) * cos(rad) - (t.second - s.second) * sin(rad) + s.first;
	u.second = (t.first - s.first) * sin(rad) + (t.second - s.second) * cos(rad) + s.second;

	koch(d - 1, p1, s);
	printf("%.8f %.8f\n", s.first, s.second);
	koch(d - 1, s, u);
	printf("%.8f %.8f\n", u.first, u.second);
	koch(d - 1, u, t);
	printf("%.8f %.8f\n", t.first, t.second);
	koch(d - 1, t, p2);
}

int main() {
	int d;
	vec p1(0., 0.), p2(100., 0.);

	cin >> d;

	printf("%.8f %.8f\n", p1.first, p1.second);
	koch(d, p1, p2);
	printf("%.8f %.8f\n", p2.first, p2.second);
}