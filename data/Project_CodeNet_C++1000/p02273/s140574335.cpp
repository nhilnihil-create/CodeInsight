#include <iostream>

#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdio>

using namespace std;

double radian = 60 * M_PI / 180.0;

struct co {
	double x;
	double y;
};

void kock(int n, co p1, co p2) {
	if (n == 0) {
		return;
	}
	co s, t, u;
	s.x = (2 * p1.x + 1 * p2.x) / 3;
	s.y = (2 * p1.y + 1 * p2.y) / 3;
	t.x = (1 * p1.x + 2 * p2.x) / 3;
	t.y = (1 * p1.y + 2 * p2.y) / 3;

	u.x = (t.x - s.x) * cos(radian) - (t.y - s.y) * sin(radian) + s.x;
	u.y = (t.x - s.x) * sin(radian) + (t.y - s.y) * cos(radian) + s.y;

	kock(n - 1, p1, s);
	printf("%.8f %.8f\n", s.x, s.y);
	kock(n - 1, s, u);
	printf("%.8f %.8f\n", u.x, u.y);
	kock(n - 1, u, t);
	printf("%.8f %.8f\n", t.x, t.y);
	kock(n - 1, t, p2);

}

int main() {
	int n;
	scanf("%d", &n);
	co p1 { 0, 0 };
	co p2 { 100, 0 };

	printf("%.8f %.8f\n", p1.x, p1.y);
	kock(n, p1, p2);
	printf("%.8f %.8f\n", p2.x, p2.y);

	return 0;
}