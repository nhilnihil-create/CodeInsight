#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld eps = 1e-8, pi = acos(-1.0);

bool eq(ld a, ld b) {
	return abs(a - b) < eps;
}

using Point = complex<ld>;
class Line {
public:
	Point a, b;
};
ld dot(Point a, Point b) {
	return real(conj(a) * b);
}

ld cross(Point a, Point b) {
	return imag(conj(a) * b);
}

int ccw(Point a, Point b, Point c) {
	b -= a, c -= a;
	if (cross(b, c) > eps) return 1;	// a,b,c??????????¨???¨???
	if (cross(b, c) < -eps) return -1;	// a,b,c???????¨???????
	if (dot(b, c) < 0) return 2;		// c,a,b????????§??´???
	if (norm(b) < norm(c)) return -2;	// a,b,c???????????´???
	return 0;							// a,c,b???????????´???
}


int main()
{
	ld x1, x2, x3, xp, y1, y2, y3, yp;
	Point p1, p2, p3, P;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp) {
		p1 = Point(x1, y1);
		p2 = Point(x2, y2);
		p3 = Point(x3, y3);
		if (ccw(p1, p2, p3) == -1) {
			swap(p2, p3);
		}
		P = Point(xp, yp);
		cout << (ccw(p1, p2, P) == 1 && ccw(p2, p3, P) == 1 && ccw(p3, p1, P) == 1 ? "YES" : "NO") << endl;
	}
	return 0;
}