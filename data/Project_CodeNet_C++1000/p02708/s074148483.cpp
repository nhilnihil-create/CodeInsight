#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
#define pb push_back
#define ff first
#define ss second
#define all(s) (s).begin(), (s).end()
const ll mod = 1e9 + 7;

ll binpow(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

int main()
{
    int n, t;
    cin >> n >> t;
    ll ans = 0, mn = 0, mx = 0;
    for (int i = 0; i <= n; i++){
        mn += i, mx += n - i;
        if (i >= t - 1)
            ans += mx - mn + 1, ans %= mod;
    }
    cout << ans << endl;
    return 0;
}