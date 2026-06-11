#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

struct Point
{
	Point() : x(0.), y(0.){}
	Point(double _x, double _y) :x(_x), y(_y){}
	double x;
	double y;
};

void KochCurve(int n, Point& p1, Point& p2)
{
	if (0 == n){
		cout << fixed << std::setprecision(5) << p1.x << " " << p1.y << "\n";
		return;
	}

	Point q1, q2, q3;
	q1.x = p1.x + (p2.x - p1.x) / 3;
	q3.x = p1.x + 2 * (p2.x - p1.x) / 3;
	q1.y = p1.y + (p2.y - p1.y) / 3;
	q3.y = p1.y + 2 * (p2.y - p1.y) / 3;
	double r3 = sqrt(3);
	q2.x = ((q3.x - q1.x) - r3 * (q3.y - q1.y)) / 2 + q1.x;
	q2.y = (r3 * (q3.x - q1.x) + (q3.y - q1.y)) / 2 + q1.y;

	KochCurve(n - 1, p1, q1);
	KochCurve(n - 1, q1, q2);
	KochCurve(n - 1, q2, q3);
	KochCurve(n - 1, q3, p2);
}

int main()
{
	int n;
	cin >> n;
	Point p1 = Point(0., 0.);
	Point p2 = Point(100., 0.);
	KochCurve(n, p1, p2);
	cout << fixed << std::setprecision(5) << p2.x << " " << p2.y << "\n";
	return 0;
}