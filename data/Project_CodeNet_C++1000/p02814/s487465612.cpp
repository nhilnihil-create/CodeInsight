#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC return 0;
using namespace std;
long long m, d, x;
int n;
int main() {
    DAU
    cin >> n >> m >> d;
    int l = __builtin_ffsll(d);
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        if (__builtin_ffsll(x) != l || d / 2 > m) {
            d = 2 * m + 2;
            break;
        }
        d *= (x / __gcd(d, x));
    }
    if (d / 2 > m)
        cout << 0;
    else cout << (m - d / 2) / d + 1;
    PLEC
}
