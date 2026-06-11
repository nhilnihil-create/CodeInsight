#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
double PI = acos(-1);
using namespace std;
class point{
public:
	double x, y;
	point(){ x = 0, y = 0; }
	point(double a, double b){ x = a, y = b; }
	friend point operator+(point a, point b){
		return point(a.x + b.x, a.y + b.y);
	}
	friend point operator/(point a, double b){
		return point(a.x / b, a.y / b);
	}
	friend point operator*(point a, double b){
		return point(a.x * b, a.y * b);
	}
};
void koch(int m, point p1, point p2){
	if (m == 0) return;
	point s, t, u;
	s = (p1 * 2.0 + p2) / 3.0;
	t = (p1 + p2 * 2.0) / 3.0;
	u.x = (t.x - s.x)*cos(PI / 3) - (t.y - s.y)*sin(PI / 3)+s.x;
	u.y = (t.x - s.x)*sin(PI / 3) + (t.y - s.y)*cos(PI / 3) + s.y;
	koch(m - 1, p1, s);
	cout << s.x << ' ' << s.y << '\n';
	koch(m - 1, s, u);
	cout << u.x << ' ' << u.y << '\n';
	koch(m - 1, u, t);
	cout << t.x << ' ' << t.y << '\n';
	koch(m - 1, t, p2);
}
int main(){
	int n; cin >> n;
	point P1, P2;
	P1.x = P1.y = 0;
	P2.x = 100; P2.y = 0;
	cout << fixed << setprecision(8);
	cout << P1.x << ' ' << P1.y << '\n';
	koch(n, P1, P2);
	cout << P2.x << ' ' << P2.y << '\n';
}