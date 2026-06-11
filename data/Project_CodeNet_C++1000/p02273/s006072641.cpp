#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double th = M_PI * 60.0 / 180.0;

void koch(int N, Point p1, Point p2)
{
    if (N == 0)
        return;

    Point s, u, t;
    s.x = (2 * p1.x + 1 * p2.x) / 3;
    s.y = (2 * p1.y + 1 * p2.y) / 3;

    t.x = (1 * p1.x + 2 * p2.x) / 3;
    t.y = (1 * p1.y + 2 * p2.y) / 3;

    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(N - 1, p1, s);
    // cout << s.x << " " << s.y << endl;
    printf("%.8f %.8f\n", s.x, s.y);

    koch(N - 1, s, u);
    // cout << u.x << " " << u.y << endl;
    printf("%.8f %.8f\n", u.x, u.y);

    koch(N - 1, u, t);
    // cout << t.x << " " << t.y << endl;
    printf("%.8f %.8f\n", t.x, t.y);

    koch(N - 1, t, p2);
    // cout << p2.x << " " << p2.y << endl;
}

int main() {
    int N;
    cin >> N;
    Point p1, p2;
    p1.x = 0.0;
    p1.y = 0.0;
    p2.x = 100.0;
    p2.y = 0.0;

    // cout << fixed << setprecision(8) << p1.x << " " << fixed << s p1.y << endl;
    printf("%.8f %.8f\n", p1.x, p1.y);
    koch(N, p1, p2);
    printf("%.8f %.8f\n", p2.x, p2.y);
}
