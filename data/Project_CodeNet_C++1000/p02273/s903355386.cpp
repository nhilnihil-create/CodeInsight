#include<cstdio>
#include<cmath>

struct Point {
	double x, y;
};

void koho(int n, Point p1, Point p2) {
	if (n == 0) {
		printf("%.8f %.8f\n", p1.x, p1.y);
		return;
	}

	double th = M_PI * 60.0 / 180.0;
	Point p3, p4, p5;
	p3.x = (2.0 * p1.x + p2.x) / 3;
	p3.y = (2.0 * p1.y + p2.y) / 3;
	p5.x = (p1.x + 2.0 * p2.x) / 3;
	p5.y = (p1.y + 2.0 * p2.y) / 3;
	p4.x = p3.x + (p5.x - p3.x) * cos(th) - (p5.y - p3.y) * sin(th);
	p4.y = p3.y + (p5.x - p3.x) * sin(th) + (p5.y - p3.y) * cos(th);

	koho(n - 1, p1, p3);
	koho(n - 1, p3, p4);
	koho(n - 1, p4, p5);
	koho(n - 1, p5, p2);
}

int main() {
	int n;
	scanf("%d", &n);
	Point s, t;
	s.x = 0;
	s.y = 0;
	t.x = 100;
	t.y = 0;
	koho(n, s, t);
	printf("%.8f %.8f\n", t.x, t.y);
}