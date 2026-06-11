#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point
{
    double x = 0.0;
    double y = 0.0;
};

void koch(int depth, point p1, point p2)
{
    if (depth == 0)
        return ;
    point s, t, u;

    const double th = M_PI * 60.0 / 180.0;

    s.x = (2 * p1.x + p2.x) / 3.0;
    s.y = (2 * p1.y + p2.y) / 3.0;

    t.x = (p1.x + 2 * p2.x) / 3;
    t.y = (p1.y + 2 * p2.y) / 3;

    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(depth - 1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(depth - 1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(depth - 1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(depth - 1, t, p2);
}


int main()
{
    int n;
    point s;
    s.x = 0.0f;
    s.y = 0.0f;
    point t;
    t.x = 100.0f;
    t.y = 0.0f;
    while (cin >> n)
    {
        printf("%.8f %.8f\n", s.x, s.y);
        koch(n, s, t);
        printf("%.8f %.8f\n", t.x, t.y);
    }
    return 0;
}
