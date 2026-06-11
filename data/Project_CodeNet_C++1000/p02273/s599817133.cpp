#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct point {
    double x, y;
};

void koch(int d, point a, point b) {
    point s, t, u;
    if(d == 0) return;
    s.x = (2*a.x + 1*b.x) / 3;
    s.y = (2*a.y + 1*b.y) / 3;
    t.x = (1*a.x + 2*b.x) / 3;
    t.y = (1*a.y + 2*b.y) / 3;
    u.x = (t.x - s.x)*cos(M_PI/3) - (t.y - s.y)*sin(M_PI/3) + s.x;
    u.y = (t.x - s.x)*sin(M_PI/3) + (t.y - s.y)*cos(M_PI/3) + s.y;

    cout << fixed;
    koch(d-1, a, s);
    cout << setprecision(8) << s.x << " " << s.y << endl;
    koch(d-1, s, u);
    cout << setprecision(8) << u.x << " " << u.y << endl;
    koch(d-1, u, t);
    cout << setprecision(8) << t.x << " " << t.y << endl;
    koch(d-1, t, b);
}

int main() {
    int n;
    cin >> n;
    point l={0, 0}, m={100, 0};
    cout << fixed;
    cout << setprecision(8) << l.x << " " << l.y << endl;
    koch(n, l, m);
    cout << setprecision(8) << m.x << " " << m.y << endl;
    return 0;
}
