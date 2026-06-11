#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

class Point {
  public:
    double x, y;
};

void koch(int n, Point a, Point b) {
    if (n == 0)
        return;

    // coord to vector
    Point s, t, u;
    double theta = M_PI * 60.0 / 180.0;
    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos(theta) - (t.y - s.y) * sin(theta) + s.x;
    u.y = (t.x - s.x) * sin(theta) + (t.y - s.y) * cos(theta) + s.y;

    // recursive
    koch(n - 1, a, s);
    cout << precise(8) << s.x << " " << s.y << endl;
    koch(n - 1, s, u);
    cout << precise(8) << u.x << " " << u.y << endl;
    koch(n - 1, u, t);
    cout << precise(8) << t.x << " " << t.y << endl;
    koch(n - 1, t, b);
}

int main() {
    fastIO;

    Point a, b;
    int n;

    cin >> n;
    a.x = 0;
    a.y = 0;
    b.x = 100;
    b.y = 0;

    cout << precise(8) << a.x << " " << a.y << endl;
    koch(n, a, b);
    cout << precise(8) << b.x << " " << b.y << endl;
}

