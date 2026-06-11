#include <iostream>
#include <cmath>


struct Point {double x, y;};
double th = M_PI * 60.0 / 180.0;


void koch (int n, Point a, Point b) {
    if (n == 0) return;
    Point s, t, u;
    s.x = (2.0 * a.x + 1. * b.x) / 3.;
    s.y = (2.0 * a.y + 1. * b.y) / 3.;

    t.x = (1.0 * a.x + 2. * b.x) / 3.;
    t.y = (1.0 * a.y + 2. * b.y) / 3.;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
    koch(n - 1, a, s);
    std::printf("%.8f %.8f\n", s.x, s.y);
    koch(n - 1, s, u);
    std::printf("%.8f %.8f\n", u.x, u.y);
    koch(n - 1, u, t);
    std::printf("%.8f %.8f\n", t.x, t.y);
    koch(n - 1, t, b);
}


int main (int argc, char ** argv) {
    int n = 0;
    std::cin >> n;
    Point p1 = {0, 0};
    Point p2 = {100, 0};
    std::printf("%.8f %.8f\n", p1.x, p1.y);
    koch(n, p1, p2);
    std::printf("%.8f %.8f\n", p2.x, p2.y);
}


