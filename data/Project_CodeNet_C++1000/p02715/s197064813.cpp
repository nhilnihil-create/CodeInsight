#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;

void add(ll &a, ll b)
{
    a = (a+b) % MOD;
}
ll mod_pow(ll x, ll n)
{
    ll res = 1;
    while(n > 0)
    {
        if(n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 0;

    vector<ll> mem(k+1);
    for(ll x = k; x >= 1; x--)
    {
        ll tmp = mod_pow(k/x, n);
        for(ll i = 2*x; i <= k; i += x)
        {
            add(tmp, -mem[i]);
            add(tmp, MOD);
        }
        mem[x] = tmp;
        add(ans, x * tmp % MOD);
        add(ans, MOD);
    }
    cout << ans << endl;
}

