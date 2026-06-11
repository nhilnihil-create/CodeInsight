// コッホ曲線
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

struct Point{
    double x, y;
};

void Koch(int n, Point a, Point b) {
    if (n == 0) return;

    Point s, t, u;

    double th = 60.0 * (M_PI / 180.0);

    s.x = (a.x * 2.0 + b.x * 1.0) / 3.0;
    s.y = (a.y * 2.0 + b.y * 1.0) / 3.0;
    t.x = (a.x * 1.0 + b.x * 2.0) / 3.0;
    t.y = (a.y * 1.0 + b.y * 2.0) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    Koch(n - 1, a, s);
    printf("%.8f %.8f\n", s.x, s.y);
    Koch(n - 1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    Koch(n - 1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    Koch(n - 1, t, b);
}

int main() {
    int n;
    Point a, b;

    cin >> n;

    a.x = 0.0;
    a.y = 0.0;
    b.x = 100.0;
    b.y = 0.0;

    printf("%.8f %.8f\n", a.x, a.y);
    Koch(n, a, b);
    printf("%.8f %.8f\n", b.x, b.y);

    return 0;
}
