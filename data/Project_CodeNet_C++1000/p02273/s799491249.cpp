#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

struct Point { double x, y; };

void print(struct Point p) {
    cout << fixed << setprecision(5) << p.x << " " << p.y << endl;
}

void koch(int n, struct Point a, struct Point b) {
    if (n == 0) return;

    struct Point s, u, t;
    double th = M_PI * 60.0 / 180.0;

    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(n - 1, a, s);
    print(s);
    koch(n - 1, s, u);
    print(u);
    koch(n - 1, u, t);
    print(t);
    koch(n - 1, t, b);
}

int main() {

    int n;
    cin >> n;

    struct Point a, b;
    a.x = 0.0;
    a.y = 0.0;
    b.x = 100.0;
    b.y = 0.0;

    print(a);
    koch(n, a, b);
    print(b);

    return 0;
}