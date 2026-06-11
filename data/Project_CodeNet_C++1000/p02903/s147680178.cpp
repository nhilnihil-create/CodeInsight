#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
void solver(ll h, ll w, ll a, ll b)
{
    rep(i, 0, b)
    {
        rep(j, 0, a) cout << '0';
        rep(j, a, w) cout << '1';
        cout << '\n';
    }
    rep(i, b, h)
    {
        rep(j, 0, a) cout << '1';
        rep(j, a, w) cout << '0';
        cout << '\n';
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    solver(h, w, a, b);
}