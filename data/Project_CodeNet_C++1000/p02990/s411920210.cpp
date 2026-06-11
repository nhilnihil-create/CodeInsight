#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 510000
#define MOD 1000000007
#define rep(i, a, n) for (ll i = a; i < n; ++i)

ll fac[MAX], finv[MAX], inv[MAX];

//二項係数の計算
void comint()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; ++i)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll com(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    comint();
    rep(i, 1, k + 1) cout << (com(k - 1, i - 1) * com(n - k + 1, i)) % MOD << endl;
}
