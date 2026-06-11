#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;

vector<ll> fact;
vector<ll> invFact;

ll binary_pow(ll n, ll p)
{
    return p ? binary_pow(n * n % MOD, p >> 1) * (p & 1 ? n : 1) % MOD : 1;
}

void init_fact(int n)
{
    fact.resize(n + 10);
    invFact.resize(n + 10);
    fact[0] = 1;
    invFact[0] = 1;
    rep (i, n)
    {
        fact[i + 1] = fact[i] * (i + 1) % MOD;
        invFact[i + 1] = invFact[i] * binary_pow(i + 1, MOD - 2) % MOD;
    }
}

ll combination(ll n, ll r)
{
    ll ret = 1;
    ret = ret * fact[n];
    ret = ret * invFact[r] % MOD;
    ret = ret * invFact[n - r] % MOD;
    return ret;
}

ll divide(ll x, ll y)
{
    if (x < y || y < 1)
        return 0;
    if (x == 0 && y == 0)
        return 1;
    ll ret;
    ret = combination((x - y) + y - 1, y - 1);
    return ret;
}

int main()
{
    int n, k;
    cin >> n >> k;

    init_fact(n + k);

    ll ans;
    for (int i = 1; i <= k; i++)
    {
        ll temp = 0;
        ans = divide(k, i);
        temp += divide(n - k, i - 1) % MOD;
        temp += divide(n - k, i) * 2 % MOD;
        temp += divide(n - k, i + 1) % MOD;
        ans = ans * temp % MOD;
        if (i == 1 && ans == 0)
            cout << 1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}