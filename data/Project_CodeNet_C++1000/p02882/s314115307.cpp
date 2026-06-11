#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ld a, b, x;
    cin >> a >> b >> x;
    ld y = a*a*b - x;
    ld Sx=x/a, Sy=y/a;
    ld Sj = a*b/2;
    ld ans;
    ld pi = 3.14159265358979323846;
    if (Sy <= Sj) {
        ld p = (2*Sy)/(a*a);
        ans = atan(p);
    }
    else {
        ld p = (b*b)/(2*Sx);
        ans = atan(p);
    }
    // ans = atan((2*Sy)/(a*a));
    ans *= 180/pi;

    cout << fixed << setprecision(8);
    cout << ans << endl;
}