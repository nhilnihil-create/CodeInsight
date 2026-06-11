#include <cstdio>
#include <cmath>
#include <utility>
using namespace std;

struct Point { double x, y; };

void print(Point p) {
    printf("%f %f\n", p.x, p.y);
}

void koch(int d, Point p1, Point p2) {
    if (d == 0) { return; }

    Point s, t, u;
    double th = M_PI * 60.0 / 180.0;

    s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(d-1, p1, s);
    print(s);
    koch(d-1, s, u);
    print(u);
    koch(d-1, u, t);
    print(t);
    koch(d-1, t, p2);
}

int main() {
    int n;
    scanf("%d", &n);

    Point p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;

    print(p1);
    koch(n, p1, p2);
    print(p2);

    return 0;
}
