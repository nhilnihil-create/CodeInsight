#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

struct Point {
	double x;
	double y;
};

void koch(int n, Point a, Point b);

int main() {
	Point a, b;
	int n;
	cin >> n;
	a.x = 0; 
	a.y = 0;
	b.x = 100;
	b.y = 0;

	cout << setprecision(10) <<  a.x << " " << a.y << endl;
	koch(n, a, b);
	cout << b.x << " " << b.y << endl;
	return 0;
}

void koch(int n, Point a, Point b) {
	if (n == 0)return;
	Point s, t, u;
	s.x = (2.0 * a.x + b.x) / 3.0;
	s.y = (2.0 * a.y + b.y) / 3.0;
	t.x = (a.x + 2.0 * b.x) / 3.0;
	t.y = (a.y + 2.0 * b.y) / 3.0;
	u.x = (t.x - s.x) / 2.0 - (t.y - s.y) * sqrt(3) / 2.0 + s.x;
	u.y = (t.x - s.x) * sqrt(3) / 2.0 + (t.y - s.y) / 2.0 + s.y;

	koch(n - 1, a, s);
	cout << s.x << " " << s.y << endl;
	koch(n - 1, s, u);
	cout << u.x << " " << u.y << endl;
	koch(n - 1, u, t);
	cout << t.x << " " << t.y << endl;
	koch(n - 1, t, b);
}