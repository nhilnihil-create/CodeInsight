#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0)
    {
        if(n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    long long n, a, b; cin >> n >> a >> b;
    long long ans = (modpow(2, n) - 1 + MOD) % MOD;
    long long xa = 1, xb = 1, ya = 1, yb = 1;
    for (int i = 0; i < a; i++)
    {
        xa = xa * (n - i) % MOD;
        ya = ya * (i+1) % MOD;
    }
    for (int i = 0; i < b; i++)
    {
        xb = xb * (n - i) % MOD;
        yb = yb * (i+1) % MOD;
    }

    long long suba = xa * modpow(ya, MOD - 2) % MOD;
    long long subb = xb * modpow(yb, MOD - 2) % MOD;
    ans = (ans - suba - subb + 2 * MOD) % MOD;

    cout << ans << endl;
    return 0;
}
