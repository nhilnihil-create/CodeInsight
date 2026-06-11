#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 510000; 

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    long long t;
    while (b)
    {
        t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

long long com(int n, int k)
{
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

long long perm(int n, int k)
{
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[n-k] % MOD;
}

int main(void)
{
    COMinit();
    int n, a, b; cin >> n >> a >> b;
    long long ans = 1;
    int m = 1;
    while (m * m <= n) m++;
    m--;
    int l = n - m * m;
    int k = 1;

    for (int i = 0; i < m; i++)
    {
        k *= 2;
        k %= MOD;
    }
    for (int i = 0; i < m; i++)
    {
        ans *= k;
        ans %= MOD;
    }
    for (int i = 0; i < l; i++)
    {
        ans *= 2;
        ans %= MOD;
    }
    ans--;
    long long xa = 1, xb = 1;
    for (int i = 0; i < a; i++)
        xa = xa * (n - i) % MOD;
    for (int i = 0; i < b; i++)
        xb = xb * (n - i) % MOD;
    ans = ans - xa * finv[a] % MOD - xb * finv[b] % MOD;
    ans = ans % MOD;
    if (ans < 0)
        ans += MOD;
    cout << ans << endl;
}