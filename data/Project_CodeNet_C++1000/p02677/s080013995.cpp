#include <bits/stdc++.h>
using namespace std;

#define newline '\n'
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
using ll = long long;
using ull = unsigned long long;

int main() {
    IOS;
    cout.precision(12);
    cout << fixed;

    int a, b, h, m;
    cin >> a >> b >> h >> m;

    double atheta = ((h + (m / 60.0)) / 12.0) * 360;
    double btheta = (m / 60.0) * 360;
    //cout << atheta << " " << btheta << newline;
    double deg = abs(atheta - btheta);
    //cout << deg << newline;

    double pi = 2 * acos(0.0);
    double rad = deg * pi / 180;

    double s = (a * a) + (b * b) - (2 * a * b * cos(rad));
    double ans = sqrt(s);

    cout << ans << newline;

    return 0;
}