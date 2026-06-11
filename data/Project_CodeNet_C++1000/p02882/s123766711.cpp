#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    double a, b, x;
    cin >> a >> b >> x;
    double s = x / a;
    double rad;
    if(s >= a * b / 2) {
        double h = (a * b - s) * 2 / a;
        rad = atan2(h, a);
    }
    else {
        double w = s * 2 / b;
        rad = atan2(b, w);
    }
    double PI = acos(-1);
    double deg = rad /(2 * PI) * 360;
    cout << setprecision(15) << deg << endl;
    return 0;
}
