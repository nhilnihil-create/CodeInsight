#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
#define int long long
int a, b, x, res(1), d(2);
main() {
    DAU
    cin >> a >> b;
    x = __gcd(a, b);
    while (x != 1) {
        if (x % d == 0) {
            ++res;
            while (x % d == 0)
                x /= d;
        }
        if (d == 2) d = 3;
        else d += 2;
        if (d * d > x) d = x;
    }
    cout << res;
    PLEC
}
