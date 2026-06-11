#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

int modpow(int x, int n) {
    int ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int modcomb(int n, int k) {
    if (n < k || n < 0 || k < 0) return 0;
    if (n - k < k) k = n - k;
    int x = 1, y = 1;
    for (int i = 0; i < k; i++) x = x * (n - i) % MOD;
    for (int i = k; i > 0; i--) y = y * i % MOD;
    return x * modpow(y, MOD - 2) % MOD;
}

signed main() {
    int x, y;
    cin>>x>>y;
    if ((x + y) % 3 != 0) {
        cout<<0<<endl;
        return 0;
    }
    int a, b;
    a = (2 * x - y) / 3;
    b = (2 * y - x) / 3;
    cout<<modcomb(a + b, a)<<endl;
}