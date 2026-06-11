#include <bits/stdc++.h>
using namespace std;

int main() {
    const double PI = acos(-1.0);
    double a, b, x;
    cin >> a >> b >> x;
    x /= a;
    cout << fixed << setprecision(10);
    if (x > a*b/2) cout << atan2((a*b-x)*2, a*a) * 180 / PI << endl;
    else cout << atan2(b*b, x*2) * 180 / PI << endl;
}