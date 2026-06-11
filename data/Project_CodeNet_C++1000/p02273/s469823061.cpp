#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1);

struct Point
{
    double x, y;
};

void koch(int n, int i, Point p1, Point p2)
{
    if(i == n) return;
    Point s, t, u, p;
    s.x = (2 * p1.x + p2.x) / 3;
    s.y = (2 * p1.y + p2.y) / 3;
    koch(n, i+1, p1, s);
    printf("%.8lf %.8lf\n", s.x, s.y);
    u.x = (p1.x + 2 * p2.x) / 3;
    u.y = (p1.y + 2 * p2.y) / 3;
    p.x = u.x - s.x;
    p.y = u.y - s.y;
    t.x = cos(PI / 3) * p.x - sin(PI / 3) * p.y + s.x;
    t.y = sin(PI / 3) * p.x + cos(PI / 3) * p.y + s.y;
    koch(n, i+1, s, t);
    printf("%.8lf %.8lf\n", t.x, t.y);
    koch(n, i+1, t, u);
    printf("%.8lf %.8lf\n", u.x, u.y);
    koch(n, i+1, u, p2);
}

int main()
{
    int n;
    cin >> n;
    Point p1, p2;
    p1.x = p1.y = p2.y = 0;
    p2.x = 100;
    printf("%.8lf %.8lf\n", p1.x, p1.y);
    koch(n, 0, p1, p2);
    printf("%.8lf %.8lf\n", p2.x, p2.y);
}

