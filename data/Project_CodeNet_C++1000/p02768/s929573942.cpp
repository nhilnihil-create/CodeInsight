#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll modpow(ll a, ll b, ll m)
{
    if (b == 0) return 1%m;
    ll u = modpow(a, b / 2, m);
    u = ((u%m) * (u%m)) % m;
    if (b%2) u = ((a%m) * (u%m))%m;
    return u;
}

const int mod = (int) 1e9 + 7;

ll ncr(ll n, ll r)
{
    if (n - r < r) r = n - r;
    ll ans = 1;
    ll fr = 1;
    for (int i = 1, j = n; i <= r; i++, j--) {
        ans = ((ans%mod) *( j%mod))%mod;
        fr = ((fr%mod)  * (i%mod)) % mod;
    }
    return ((ans%mod) * modpow(fr, mod - 2, mod)) % mod;
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    ll ans = modpow(2, n, mod) - 1;
    ans = ans - ncr(n, a) - ncr(n, b);
    cout << (ans%mod + mod)%mod << "\n";
}

int main()
{

    int t = 1;
    while (t--) 
    {
        solve();
    }
}
