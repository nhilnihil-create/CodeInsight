#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
    void print() {
        cout << fixed << setprecision(8) <<
            this->x << " " << this->y << endl;
    }
};


void koch(const int& depth, const Point& a, const Point& b) {
    if (depth == 0) { return; }
    const double theta = M_PI / 3.0;

    Point s(
        (2.0 * a.x + b.x) / 3.0,
        (2.0 * a.y + b.y) / 3.0
    );

    Point t(
        (a.x + 2.0 * b.x) / 3.0,
        (a.y + 2.0 * b.y) / 3.0
    );

    Point u(
        (t.x - s.x) * cos(theta) - (t.y - s.y) * sin(theta) + s.x,
        (t.x - s.x) * sin(theta) + (t.y - s.y) * cos(theta) + s.y
    );

    koch(depth - 1, a, s);
    s.print();
    koch(depth - 1, s, u);
    u.print();
    koch(depth - 1, u, t);
    t.print();
    koch(depth - 1, t, b);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    Point a(0, 0);
    Point b(100, 0);

    a.print();
    koch(n, a, b);
    b.print();

    return 0;
}