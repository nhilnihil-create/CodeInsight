#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf (1 << 21)
#define mod 1000000007

int main() {
    double a, b, x; cin >> a >> b >> x;
    double bx = x / pow(a, 2);
    double y = b - bx;
    double rad,theta;
    if (bx - y >= 0) {
        rad = atan(2 * y / a);
    }
    else {
        double xa = (2 * x) / (a * b);
        if (xa > 0) {
            rad = atan(b / xa);
        }
        else {
            rad = pi / 2;
        }
    }
    theta = (rad * (double)180) / pi;
    cout << fixed << setprecision(10);
    cout << theta << endl;
    return 0;
}
