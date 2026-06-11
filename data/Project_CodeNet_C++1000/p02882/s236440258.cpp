#include <bits/stdc++.h>
using namespace std;

int main() {
    double ans;
    double a, b, x;
    cin >> a >> b >> x;
    double y = 2 * (a * a * b - x);
    if(y <= a * a * b)
        ans = atan2(y, a * a * a);
    else {
        y = 2 * x;
        ans = atan2(a * b * b, y);
    }
    ans *= 180;
    ans /= M_PI;
    cout << fixed << setprecision(10) << ans << endl;
}