#include <bits/stdc++.h>
using namespace std;
static const double cos60 = 0.5;
static const double sin60 = sqrt(3) / 2;

class Point {
    public:
        double x;
        double y;
};

void koch(int d, Point p1, Point p2) {
    if (d == 0) return;
    Point s, u, t;
    s.x = (2 * p1.x + p2.x) / 3;
    s.y = (2 * p1.y + p2.y) / 3;
    t.x = (p1.x + 2 * p2.x) / 3;
    t.y = (p1.y + 2 * p2.y) / 3;
    u.x = (t.x - s.x) * cos60 - (t.y - s.y) * sin60 + s.x;
    u.y = (t.x - s.x) * sin60 + (t.y - s.y) * cos60 + s.y;
    koch(d-1, p1, s);
    cout << fixed << setprecision(8) << s.x << " " << s.y << endl;
    koch(d-1, s, u);
    cout << fixed << setprecision(8) << u.x << " " << u.y << endl;
    koch(d-1, u, t);
    cout << fixed << setprecision(8) << t.x << " " << t.y << endl;
    koch(d-1, t, p2);
}

int main() {
    int n;
    cin >> n;
    Point p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    cout << fixed << setprecision(8) << p1.x << " " << p1.y << endl;
    koch(n, p1, p2);
    cout << fixed << setprecision(8) << p2.x << " " << p2.y << endl;
    
    return 0;
}
