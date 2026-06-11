#include <iostream>
#include <ios>
#include <list>
#include <iomanip>
#include <math.h>
using namespace std;
#define FOR(it) for(Points::iterator it = list.begin(); it != list.end(); ++it)
struct Point
{
	Point(double _x, double _y) :x(_x), y(_y){}
	double x;
	double y;
};
typedef list<Point> Points;

void CreatePoints(const Point& p1, const Point& p2, Points& ps)
{
	double x1, x2, x3, y1, y2, y3;
	x1 = p1.x + (p2.x - p1.x) / 3;
	x3 = p1.x + 2 * (p2.x - p1.x) / 3;
	y1 = p1.y + (p2.y - p1.y) / 3;
	y3 = p1.y + 2 * (p2.y - p1.y) / 3;
	double r3 = sqrt(3);
	x2 = ((x3 - x1) - r3 * (y3 - y1))/2 + x1;
	y2 = (r3 * (x3 - x1) + (y3 - y1))/2 + y1;
	ps.push_back(Point(x1, y1));
	ps.push_back(Point(x2, y2));
	ps.push_back(Point(x3, y3));
}

void KochCurve(int n, Points& list)
{
	if (0 == n) return;
	Points::iterator it, preit;
	for (it = list.begin(); it != list.end(); ++it){
		if (it == list.begin()){
			preit = it;
			continue;
		}

		Points addPs;
		CreatePoints(*preit, *it, addPs);
		list.insert(it, addPs.begin(), addPs.end());
		preit = it;
	}
	
	return KochCurve(n - 1, list);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	Points list;
	list.push_back(Point(0., 0.));
	list.push_back(Point(100., 0.));
	KochCurve(n, list);
	FOR(it)
		cout << fixed << std::setprecision(5) << it->x << " " << it->y << "\n";

	return 0;
}