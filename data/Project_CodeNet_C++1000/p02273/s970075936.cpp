#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
struct Point { double x, y; };
double six = M_PI / 3;
int koch(int d, Point p1, Point p2) {
    if (d == 0) return 0;
    Point s, u, t;
    s.x = (2*p1.x + p2.x) / 3;
    s.y = (2*p1.y + p2.y) / 3;
    t.x = (p1.x + 2*p2.x) / 3;
    t.y = (p1.y + 2*p2.y) / 3;
    u.x = (t.x - s.x) * cos(six) - (t.y - s.y) * sin(six) + s.x;
    u.y = (t.x - s.x) * sin(six) + (t.y - s.y) * cos(six) + s.y;
    koch(d-1, p1, s);
    cout << fixed << setprecision(8) << s.x << " " << s.y << endl;
    koch(d-1, s, u);
    cout << u.x << " " << u.y << endl;
    koch(d-1, u, t);
    cout << t.x << " " << t.y << endl;
    koch(d-1, t, p2);
    return 0;
	}

int main() {

    int n;
    Point p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    cin >> n;
    cout << fixed << setprecision(8) << p1.x << " " << p1.y << endl;
    koch(n, p1, p2);
    cout << p2.x << " " << p2.y << endl;
    return 0;
}