#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

static const double pi = 3.141592653589793;
double rad = 60 * (pi / 180);

struct Point {
    double x;
    double y;
};

void koch(int n, Point a, Point b) {
    if (n == 0) {
        return;
    }
    
    Point s, t, u;
    s.x = (2 * a.x + 1 * b.x) / 3;
    s.y = (2 * a.y + 1 * b.y) / 3;
    t.x = (1 * a.x + 2 * b.x) / 3;
    t.y = (1 * a.y + 2 * b.y) / 3;
    u.x = (t.x - s.x) * cos(rad) - (t.y - s.y) * sin(rad) + s.x;
    u.y = (t.x - s.x) * sin(rad) + (t.y - s.y) * cos(rad) + s.y;
    
    koch(n - 1, a, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(n - 1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(n - 1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(n - 1, t, b);

    return;
}

int main() {
    int n;
    cin >> n;
    Point a, b;
    a.x = 0;
    a.x = 0;
    b.x = 100;
    b.y = 0;

    printf("%.8f %.8f\n", a.x, a.y);
    koch(n, a, b);
    printf("%.8f %.8f\n", b.x, b.y);

    return 0;
}
