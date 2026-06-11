/**
 *  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C
 */
#include <iostream>
#include <iomanip>

#define SQRT_3 1.73205080757

using namespace std;

constexpr double
ccw60x(const double ax, const double ay, const double bx, const double by)
{
    return (bx - ax) / 2 - (by - ay) * SQRT_3 / 2 + ax;
}
constexpr double
ccw60y(const double ax, const double ay, const double bx, const double by)
{
    return (bx - ax) * SQRT_3 / 2 + (by - ay) / 2 + ay;
}

void
koch(const int n, const double ax, const double ay, const double bx, const double by)
{
    if (n == 0) return;

    double sx = (2 * ax + bx) / 3;
    double sy = (2 * ay + by) / 3;
    koch(n - 1, ax, ay, sx, sy);
    cout << sx << ' ' << sy << endl;

    double tx = (ax + 2 * bx) / 3;
    double ty = (ay + 2 * by) / 3;
    double ux = ccw60x(sx, sy, tx, ty);
    double uy = ccw60y(sx, sy, tx, ty);
    koch(n - 1, sx, sy, ux, uy);
    cout << ux << ' ' << uy << endl;
    koch(n -1, ux, uy, tx, ty);
    cout << tx << ' ' << ty << endl;
    koch(n -1, tx, ty, bx, by);
}

int
main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n; cin.ignore();

    double ax = 0;
    double ay = 0;
    double bx = 100;
    double by = 0;
    cout << fixed << setprecision(8) << ax << ' ' << ay << endl;
    koch(n, ax, ay, bx, by);
    cout << bx << ' ' << by << endl;

    return 0;
}