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
    ll d[m + 1];
    bool v[m + 1] = {};
    rep(i, 0, m + 1)
    {
        d[i] = i;
    }
    rep(i, 2, sqrt(m) + 1)
    {
        for (ll j = i * 2; j <= m; j += i)
        {
            if (d[j] == j)
                d[j] = i;
        }
    }
    rep(i, 0, n)
    {
        vector<ll> tmp;
        while (a[i] != 1)
        {
            ll r = d[a[i]];
            if (v[r])
            {
                cout << "setwise coprime\n";
                return;
            }
            tmp.push_back(r);
            a[i] /= r;
        }
        rep(j, 0, tmp.size())
        {
            v[tmp[j]] = true;
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