#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
const double th = M_PI * 60.0 / 180.0;
struct Point
{
    double x;
    double y;
};

void KochCurve(Point p1, Point p2, int i)
{
    if (i == n)
    {
        printf("%.8lf %.8lf\n", p1.x, p1.y);
        return;
    }
    else
    {
        Point s, u, t;
        s.x = (p1.x * 2.0 + p2.x * 1.0) / 3.0;
        s.y = (p1.y * 2.0 + p2.y * 1.0) / 3.0;
        t.x = (p1.x * 1.0 + p2.x * 2.0) / 3.0;
        t.y = (p1.y * 1.0 + p2.y * 2.0) / 3.0;
        u.x = s.x + (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th);
        u.y = s.y + (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th);
        KochCurve(p1, s, i + 1);
        KochCurve(s, u, i + 1);
        KochCurve(u, t, i + 1);
        KochCurve(t, p2, i + 1);
    }
}

int main()
{
    cin >> n;
    Point p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    KochCurve(p1, p2, 0);
    printf("%.8lf %.8lf\n", p2.x, p2.y);
    return 0;
}
