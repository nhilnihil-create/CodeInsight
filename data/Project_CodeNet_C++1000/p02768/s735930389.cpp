#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF 2e18
#define MOD (long) (1e9 + 7)
#define umap unordered_map

map<long, long> d;

long pot2(long n)
{
    if (d.count(n)) return d[n];
    if (n == 0) return 1;
    if (n == 1) return 2;
    d[n] = ((pot2(n/2) % MOD) * (pot2((n+1) / 2) % MOD)) % MOD;
    return d[n];
}

long inv(long x)
{
    long k = MOD - 2;
    long pot = x;
    long y = 1;
    while (k > 0) {
        if (k & 1) y = (y * pot) % MOD;
        pot = (pot * pot) % MOD;
        k >>= 1;
    }
    return y;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long t = 1;
    //cin >> t;

    while (t--) {
        long n, a, b;
        cin >> n >> a >> b;

        long ans = pot2(n) - 1;
        long aux = 1;
        for (long i = n-a+1; i <= n; i++) {
            aux = (aux * i) % MOD;
        }
        for (long i = 1; i <= a; i++) {
            aux = (aux * inv(i)) % MOD;
        }
        ans = (ans - aux) % MOD;
        aux = 1;
        for (long i = n-b+1; i <= n; i++) {
            aux = (aux * i) % MOD;
        }
        for (long i = 1; i <= b; i++) {
            aux = (aux * inv(i)) % MOD;
        }
        ans = (ans - aux) % MOD;
        if (ans < 0) ans = (ans + MOD) % MOD;
        printf("%lld\n", ans);
    }
}
