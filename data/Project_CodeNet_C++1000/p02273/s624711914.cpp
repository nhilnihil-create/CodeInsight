#include <iostream>
#include <cstdio>
using namespace std;

#define ROOT3 1.73205080757



class Point {
public :
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	Point() {
	}

	double x;
	double y;
	void setPoint(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

void kochCurve(int n, Point p1, Point p2) {

	if (n == 0) {
		//cout << p1.x << " " << p1.y << endl;
		printf("%.8lf %.8lf\n",p1.x,p1.y);
		if (p2.x == 100) {
			//cout << p2.x << " " << p2.y << endl;
			printf("%.8lf %.8lf\n", p2.x, p2.y);
		}
		return;
	}

	double lx;
	double ly;
	lx = p2.x - p1.x;
	ly = p2.y - p1.y;
	Point s(p1.x + lx / 3, p1.y + ly / 3);
	Point t(p1.x+lx/3*2,p1.y+ly/3*2);
	Point u;
	if (p1.y == p2.y) {
		u.setPoint(p1.x + lx / 2, p1.y + (lx / 6 )* ROOT3);
	}
	else if (lx*ly>0) {
		u.setPoint(p1.x, p1.y + (ly / 3) * 2);
	}
	else if (lx*ly < 0) {
		u.setPoint(p2.x,p1.y+(ly/3));
	}

	kochCurve(n - 1, p1, s);
	kochCurve(n - 1, s, u);
	kochCurve(n - 1, u, t);
	kochCurve(n - 1, t, p2);

}


int main(void)
{
	int n;

	cin >> n;

	Point p1(0,0);
	Point p2(100, 0);

	kochCurve(n,p1,p2);

	return 0;
}