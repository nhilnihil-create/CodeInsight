#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i, start, end) for(int i = (start); i < (end); ++i)
#define REP(i, n) FOR(i, 0, n)

constexpr double ROOT3 = 1.7320508075688772;

struct Point {
    double x;
    double y;
    Point(double xx, double yy) : x(xx), y(yy) {}

    Point operator+(const Point& other) const
    {
        return Point(x+other.x, y+other.y);
    }

    Point operator-(const Point& other) const
    {
        return Point(x-other.x, y-other.y);
    }

    Point rotate60() const
    {
        double xx = 0.5*x       - 0.5*ROOT3*y;
        double yy = 0.5*ROOT3*x + 0.5*y;
        return Point(xx, yy);
    }

    void print() const
    {
        printf("%lf %lf\n", x, y);
    }
};

Point operator*(double t, Point p)
{
    return Point(t*p.x, t*p.y);
}

void koch(const Point& p1, const Point& p2, int n)
{
    if(n == 0) {
        p2.print();
        return;
    }

    Point s = 2.0/3.0*p1 + 1.0/3.0*p2;
    Point t = 1.0/3.0*p1 + 2.0/3.0*p2;
    Point u = s + (t-s).rotate60();

    koch(p1, s, n-1);
    koch(s,  u, n-1);
    koch(u,  t, n-1);
    koch(t, p2, n-1);
}

int main()
{
    int n;
    scanf("%d", &n);

    Point p1(  0.0, 0.0);
    Point p2(100.0, 0.0);
    p1.print();
    koch(p1, p2, n);

    return 0;
}