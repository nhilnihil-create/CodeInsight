#include <cstdio>
#include <cmath>
using namespace std;

typedef struct Point {
	double x, y;
	Point(double x = 0, double y = 0) {
		this->x = x;
		this->y = y;
	}
} Point;

const double theta = acos(-1.0)/3.0;

inline void ShowPoint(const Point& p)
{
	printf("%.8lf %.8lf\n",p.x,p.y);
}

void DFS(Point a, Point b, int n)
{
	if(n == 0) {
		return;
	}
	Point s = Point(a.x+  (b.x-a.x)/3.0, a.y+  (b.y-a.y)/3.0);
	Point t = Point(a.x+2*(b.x-a.x)/3.0, a.y+2*(b.y-a.y)/3.0);
	Point u = Point((t.x-s.x)*cos(theta)-(t.y-s.y)*sin(theta)+s.x,
					(t.y-s.y)*cos(theta)+(t.x-s.x)*sin(theta)+s.y);
	
	DFS(a, s, n-1); ShowPoint(s);
	DFS(s, u, n-1); ShowPoint(u);
	DFS(u, t, n-1); ShowPoint(t);
	DFS(t, b, n-1);
}

int main()
{
	int n; scanf("%d",&n);
	
	Point a = Point(0.0, 0.0);
	Point b = Point(100.0, 0.0);
	
	ShowPoint(a);
	
	DFS(a, b, n);
	
	ShowPoint(b);
	
	return 0;
}

