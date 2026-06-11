#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;
struct Point {
	double x, y;
};
int koch(Point p1,Point p2,int n);


int main() {
	int n;
	Point p1 = { 0,0 }, p2 = {100,0};
	cin >> n;
	cout << p1.x << " " << p1.y << endl;
	koch(p1,p2, n);
	cout << p2.x << " " << p2.y << endl;
	return 0;
}

int koch(Point p1, Point p2, int n) {
	Point u,s,t;
	double th;
	s.x = (2 * p1.x + p2.x) / 3.0;
	s.y = (2 * p1.y + p2.y) / 3.0;
	t.x = (p1.x + 2 * p2.x) / 3.0;
	t.y = (p1.y + 2 * p2.y) / 3.0;
	th = M_PI / 3.0;
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = s.y + (t.x - s.x) * sin(th) +(t.y- s.y) * cos(th);
	if (n == 0){ 
		return 0;
	}
	else {
		koch(p1, s, n - 1);
		cout << s.x << " " << s.y << endl;
		koch(s,u, n - 1);
		cout << u.x << " " << u.y << endl;
		koch(u,t, n - 1);
		cout << t.x << " " << t.y << endl;
		koch(t,p2 ,n - 1);
	}
}