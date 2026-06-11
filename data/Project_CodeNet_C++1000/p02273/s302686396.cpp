#include "iostream"
#include "iomanip"
#include "math.h"

using namespace std;

static const double rad60 = 60.0 * 3.141592 / 180.0;

struct Pos {
	double x, y;
};

void solve( int n, int d, Pos start, Pos end ) {

	Pos p[5];

	p[0].x = start.x;
	p[1].x = ( end.x + start.x*2 ) / 3;
	p[3].x = ( end.x*2 + start.x ) / 3;
	p[4].x = end.x;

	p[0].y = start.y;
	p[1].y = (end.y + start.y*2) / 3;
	p[3].y = (end.y*2 + start.y) / 3;
	p[4].y = end.y;

	p[2].x = (p[3].x - p[1].x)*cos(rad60) - (p[3].y - p[1].y)*sin(rad60) + p[1].x;
	p[2].y = (p[3].x - p[1].x)*sin(rad60) + (p[3].y - p[1].y)*cos(rad60) + p[1].y;

	if (n == d + 1) {
		for (int i = 0; i < 4; i++) {
			cout << fixed << setprecision(8) << p[i].x << " "
				 << fixed << setprecision(8) << p[i].y << endl;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			solve(n, d + 1, p[i], p[i + 1]);
		}
	}
	
}

int main() {

	int n;
	cin >> n;

	Pos s, e;

	s.x = 0;
	s.y = 0;
	e.x = 100;
	e.y = 0;
	if (n == 0) {
	cout << fixed << setprecision(8) << s.x << " " 
		 << fixed << setprecision(8) << s.y << endl;
	cout << fixed << setprecision(8) << e.x << " " 
		 << fixed << setprecision(8) << e.y << endl;

	}
	else {
		solve(n, 0, s, e);

		cout << fixed << setprecision(8) << e.x << " "
			 << fixed << setprecision(8) << e.y << endl;
	}
	return 0;
}