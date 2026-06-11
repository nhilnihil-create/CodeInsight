#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

void koch(int n, Point p1, Point p2) {
    if (n == 0) {
        return;
    }
    
    Point s, t, u;
    s.x = (2 * p1.x + p2.x) / 3;
    s.y = (2 * p1.y + p2.y) / 3;
    t.x = (p1.x + 2 * p2.x) / 3;
    t.y = (p1.y + 2 * p2.y) / 3;
    u.x = (t.x - s.x) * cos(M_PI / 3) - (t.y - s.y) * sin(M_PI / 3) + s.x;
    u.y = (t.x - s.x) * sin(M_PI / 3) + (t.y - s.y) * cos(M_PI / 3) + s.y;

    koch(n - 1, p1, s);
    printf("%.8lf %.8lf\n", s.x, s.y);
    koch(n - 1, s, u);
    printf("%.8lf %.8lf\n", u.x, u.y);
    koch(n - 1, u, t);
    printf("%.8lf %.8lf\n", t.x, t.y);
    koch(n - 1, t, p2);
}

int main() {
    int n;
    cin >> n;
    Point p1, p2;
    p1.x = 0.0;
    p1.y = 0.0;
    p2.x = 100.0;
    p2.y = 0.0;

    printf("%.8lf %.8lf\n", p1.x, p1.y);
    koch(n, p1, p2);
    printf("%.8lf %.8lf\n", p2.x, p2.y);
}
