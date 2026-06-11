#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
};

double th = M_PI * 60 / 180;

void koch(int d, point p1, point p2) {
    if(d == 0) return;
    point s, t, u;
    s.x = (2 * p1.x + p2.x) / 3;
    s.y = (2 * p1.y + p2.y) / 3;
    t.x = (p1.x + 2 * p2.x) / 3;
    t.y = (p1.y + 2 * p2.y) / 3;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(d - 1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(d - 1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(d - 1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(d - 1, t, p2);
}

int main() {
    int n;

    point p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;

    cin >> n;
    cout << p1.x << " " << p1.y << endl;
    koch(n, p1, p2);
    cout << p2.x << " " << p2.y << endl;
}
