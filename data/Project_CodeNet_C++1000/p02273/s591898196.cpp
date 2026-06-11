#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#define BIG 1000000000
#define SIZE 40
#define PI 3.14159265359
using namespace std;

struct Point {
	double x, y;
	void show();
	void init(double a, double b) { x = a; y = b; }
};


void Point::show() {
	printf("%.8f %.8f\n", x, y);
}

void koch(int n, Point a, Point b) {
	if (n == 0)return;

	Point s, t, u;
	s.x = (2 * a.x + b.x) / 3;
	s.y = (2 * a.y + b.y) / 3;
	t.x = (2 * b.x + a.x) / 3;
	t.y = (2 * b.y + a.y) / 3;
	u.x = (t.x - s.x)*cos(PI / 3) - (t.y - s.y)*sin(PI / 3) + s.x;
	u.y = (t.x - s.x)*sin(PI / 3) + (t.y - s.y)*cos(PI / 3) + s.y;

	koch(n - 1, a, s);
	s.show();
	koch(n - 1, s, u);
	u.show();
	koch(n - 1, u, t);
	t.show();
	koch(n - 1, t, b);
}

int main() {
	int n;
	cin >> n;
	Point a, b;
	a.init(0, 0);
	b.init(100, 0);
	a.show();
	koch(n, a, b);
	b.show();
	return 0;
}