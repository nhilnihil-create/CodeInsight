#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

struct Point {
	double x;
	double y;
};

vector<Point> Points[2];
int zeroOne;
int oneZero;
int n;

void getPoints(Point *p1, Point *p2, Point *s, Point *u, Point *t) {
	s->x = (2.0*p1->x + p2->x) / 3.0;
	s->y = (2.0*p1->y + p2->y) / 3.0;
	t->x = (2.0*p2->x + p1->x) / 3.0;
	t->y = (2.0*p2->y + p1->y) / 3.0;
	double dx = p2->x - p1->x;
	double dy = p2->y - p1->y;
	u->x = (p1->x + p2->x) / 2.0 - dy * sqrt(3.0) / 6.0;
	u->y = (p1->y + p2->y) / 2.0 + dx * sqrt(3.0) / 6.0;
}

void koch() {
	Points[oneZero].clear();
	Point p1, p2, s, u, t;
	for (int i = 0; i < Points[zeroOne].size()-1; ++i) {
		p1 = Points[zeroOne][i];
		p2 = Points[zeroOne][i+1];
		getPoints(&p1, &p2, &s, &u, &t);
		Points[oneZero].push_back(p1);
		Points[oneZero].push_back(s);
		Points[oneZero].push_back(u);
		Points[oneZero].push_back(t);
	}
	Points[oneZero].push_back(Points[zeroOne][Points[zeroOne].size()-1]);
}

int main() {
	scanf("%d", &n);

	Point p1, p2;
	p1.x = 0.0;
	p1.y = 0.0;
	p2.x = 100.0;
	p2.y = 0.0;
	zeroOne = 0;
	oneZero = 1;
	Points[zeroOne].push_back(p1);
	Points[zeroOne].push_back(p2);
	for (int i = 0; i < n; ++i) {
		koch();
		int temp = zeroOne;
		zeroOne = oneZero;
		oneZero = temp;
	}
	for (int i = 0; i < Points[zeroOne].size(); ++i) {
		printf("%.8f %.8f\n", Points[zeroOne][i].x, Points[zeroOne][i].y);
	}

	return 0;
}