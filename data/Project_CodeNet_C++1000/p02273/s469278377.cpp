#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
using namespace std;

struct point { double x, y; };

int koch(int d,struct point l,struct point r) {
	if (d == 0)return 0;
	struct point s, u, t;
	double th = M_PI*60.0 / 180.0;
	
	s.x = (2 * l.x + r.x) / 3;
	s.y = (2 * l.y + r.y) / 3;
	t.x = (l.x + 2 * r.x) / 3;
	t.y = (l.y + 2 * r.y) / 3;
	u.x = (t.x - s.x)*cos(th) - (t.y - s.y)*sin(th) + s.x;
	u.y = (t.x - s.x)*sin(th) + (t.y - s.y)*cos(th) + s.y;

	koch(d - 1, l, s);
	cout << fixed << setprecision(8) << s.x << " " << s.y << endl;
	koch(d - 1, s, u);
	cout << fixed << setprecision(8) << u.x << " " << u.y << endl;
	koch(d - 1, u, t);
	cout <<fixed << setprecision(8) << t.x << " " << t.y << endl;
	koch(d - 1, t, r);
}
int main() {
	int n;
	struct point p1, p2;
	p1.x = 0, p1.y = 0;
	p2.x = 100, p2.y = 0;
	cin >> n;
	cout << fixed << setprecision(8) << p1.x << " " << p1.y << endl;
	koch(n, p1, p2);
	cout << fixed << setprecision(8) << p2.x <<" "<< p2.y << endl;
	return 0;
}