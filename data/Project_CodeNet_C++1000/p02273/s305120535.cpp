#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
static const double pi = 3.14159265359;

int n;
struct Point { double x, y; };
//線分を三分して三角形に
void koch(Point p1 ,Point p2,int i ) {
	if (i == n) {
		return;
	}
	Point s, t, u;
	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 3;
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	u.x = (t.x - s.x) * cos(pi / 3) - (t.y - s.y) * sin(pi / 3) + s.x;
	u.y = (t.x - s.x) * sin(pi / 3) + (t.y - s.y) * cos(pi / 3) + s.y;
	koch(p1, s, i + 1);
	printf("%.8f %.8f\n", s.x, s.y);
	koch(s, u, i + 1);
	printf("%.8f %.8f\n", u.x, u.y);
	koch(u, t, i + 1);
	printf("%.8f %.8f\n", t.x, t.y);
	koch(t, p2, i + 1);
	
}

//二分探索
int main() {
	cin >> n;
	Point p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = 100;
	p2.y = 0;
	printf("%.8f %.8f\n", p1.x, p1.y);
	koch(p1, p2, 0);
	printf("%.8f %.8f\n", p2.x, p2.y);

}
