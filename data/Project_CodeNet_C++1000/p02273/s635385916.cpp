/*
 * ALDS1_5_C.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: 13743
 */

#include<cstdio>
#include<cmath>

double SQRT3 = sqrt(3);

struct Point {
	double x;
	double y;
};

void kochCurve(Point p1, Point p2, int n) {
	if(n == 0) {
		printf("%f %f\n", p1.x, p1.y);
		return;
	}
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	Point s = {p1.x + dx/3, p1.y + dy/3};
	Point t = {p2.x - dx/3, p2.y - dy/3};
	Point st = {t.x - s.x, t.y - s.y};
	Point u = {s.x + (st.x - SQRT3*st.y)/2, s.y + (SQRT3*st.x + st.y)/2};
	kochCurve(p1, s, n-1);
	kochCurve(s, u, n-1);
	kochCurve(u, t, n-1);
	kochCurve(t, p2, n-1);
}

int main() {
	int n;
	scanf("%d", &n);
	Point l = {0, 0};
	Point r = {100, 0};
	kochCurve(l, r, n);
	printf("100.0 0.0\n");
}

