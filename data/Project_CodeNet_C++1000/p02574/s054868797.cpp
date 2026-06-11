
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
void solver(ll *a, ll n)
{
    ll ans = a[0];
    rep(i, 1, n) ans = gcd(ans, a[i]);
    if (ans != 1)
    {
        cout << "not coprime\n";
        return;
    }
    ll m = 0;
    rep(i, 0, n) m = max(m, a[i]);
    ll v[m + 1] = {};
    rep(i, 0, n)
    {
        if (a[i] == 1)
            continue;
        if (v[a[i]] == 1)
        {
            cout << "setwise coprime\n";
            return;
        }
        v[a[i]] = 1;
    }
    rep(i, 2, m + 1)
    {
        ll c = 0;
        for (ll j = i; j <= m; j += i)
        {
            c += v[j];
            if (c > 1)
            {
                cout << "setwise coprime\n";
                return;
            }
        }
    }
    cout << "pairwise coprime\n";
    return;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    solver(a, n);
}