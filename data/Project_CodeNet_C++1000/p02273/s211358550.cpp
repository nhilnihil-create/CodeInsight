#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.0)

struct Point {
    double x, y;
};

int n;

int Plot(Point p1, Point p2, int counter) {
    if (counter >= n) return 0;

    double angle = 60.0 * (PI / 180.0); // degree to rad
    Point s, t, u;
    s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
    u.x = (t.x - s.x) * cos(angle) - (t.y - s.y) * sin(angle) + s.x;
    u.y = (t.x - s.x) * sin(angle) + (t.y - s.y) * cos(angle) + s.y;
    counter++;

    Plot(p1, s, counter);
    printf("%.8lf %.8lf\n", s.x, s.y);
    Plot(s, u, counter);
    printf("%.8lf %.8lf\n", u.x, u.y);
    Plot(u, t, counter);
    printf("%.8lf %.8lf\n", t.x, t.y);
    Plot(t, p2, counter);
}

int main() {
    const Point first = {0.0, 0.0}, second = {100.0, 0.0};

    cin >> n;
    printf("%.8lf %.8lf\n", first.x, first.y);
    Plot(first, second, 0);
    printf("%.8lf %.8lf\n", second.x, second.y);

    return 0;
}
