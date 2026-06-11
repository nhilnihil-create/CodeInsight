#include <bits/stdc++.h>

using namespace std;
const int base = 1e9 + 7;
long long fastPow(long long a, long long n) {
    long long res = 1;
    for (; n > 0; n >>= 1, a = a * a % base) 
        if (n & 1)
            res = res * a % base;
    return res;
}
long long f[100005];
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    long long res  = 0;
    for (int i = k; i >= 1; --i) {
        f[i] = 1ll * fastPow(k / i, n) % base;
        for (int j = i + i; j <= k; j += i)
            f[i] -= f[j];
        f[i] %= base;
        if (f[i] < 0) f[i] += base;
        res += 1ll* i * f[i];
        res %= base;
    }
    cout << res;
    return 0;
}