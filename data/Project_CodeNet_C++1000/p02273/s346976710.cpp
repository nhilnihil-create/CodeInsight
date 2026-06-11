#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int n;

typedef struct _point {
    double x;
    double y;
} Point;

void print_point(Point p) {
    printf("%.8f %.8f\n", p.x, p.y);
}

void koch_curve(Point p1, Point p2, int i) {
    if (i == n) {
        return;
    }

    Point s, t, u;
    double th = M_PI * 60.0 / 180.0;
    s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch_curve(p1, s, i + 1);
    print_point(s);
    koch_curve(s, u, i + 1);
    print_point(u);
    koch_curve(u, t, i + 1);
    print_point(t);
    koch_curve(t, p2, i + 1);
}

int main() {
    cin >> n;

    Point start = {0, 0};
    Point end = {100, 0};

    print_point(start);
    koch_curve(start, end, 0);
    print_point(end);
}
