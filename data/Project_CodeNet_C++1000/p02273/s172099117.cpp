#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;
#define Pi 3.1415926

class P {
public:
	double x, y;
	P() :x(0), y(0) {}
	P(double a, double b) :x(a), y(b) {}
	void print() {
		cout << setprecision(8) <<fixed<< x << " " << y << endl;
	}
};

void koch(int n, P p1, P p2) {
	P s, u, t;
	double th = Pi* 60 /180.0;
	if (n == 0) return;

	s.x = (2.0*p1.x + 1.0*p2.x) / 3.0;
	s.y = (2.0*p1.y + 1.0*p2.y) / 3.0;
	t.x = (1.0*p1.x + 2.0*p2.x) / 3.0;
	t.y = (1.0*p1.y + 2.0*p2.y) / 3.0;
	u.x = (t.x - s.x)*cos(th) - (t.y - s.y)*sin(th) + s.x;
	u.y = (t.x - s.x)*sin(th) + (t.y - s.y)*cos(th) + s.y;

	koch(n - 1, p1, s);
	s.print();
	koch(n - 1, s, u);
	u.print();
	koch(n - 1, u, t);
	t.print();
	koch(n - 1, t, p2);
}

int main(){
	P a(0.0,0.0), b(100.0,0.0);
	int n;
	cin >> n;

	a.print();
	koch(n,a, b);
	b.print();

	return 0;
}