#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
#define int long long
const int MOD(1e9 + 7);
inline int Powlog(int a, int b) {
    int res(1);
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int x, y, n, k, f1, f2, f3, res;
int32_t main() {
    DAU
    cin >> x >> y;
    if ((x + y) % 3) {
        cout << 0;
        PLEC
    }
    n = (x + y) / 3;
    k = min(x, y) - (x + y) / 3;
 	if (k < 0) {
    	cout << 0;
      	PLEC
    }
    f1 = f2 = f3 = 1;
    for (int i = 1; i <= n; ++i)
        f1 = (f1 * i) % MOD;
    for (int i = 1; i <= k; ++i)
        f2 = (f2 * i) % MOD;
    for (int i = 1; i <= n - k; ++i)
        f3 = (f3 * i) % MOD;
    res = ((f1 * Powlog(f2, MOD - 2)) % MOD * Powlog(f3, MOD - 2)) % MOD;
    cout << res;
    PLEC
}