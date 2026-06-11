#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

int main()
{
    ll n, x, d = 0, ans = 1;
    cin >> n >> x;
    ll l[n];
    rep(i, n) cin >> l[i];
    rep(i, n)
    {
        d += l[i];
        if (d <= x)
            ans++;
    }
    cout << ans << endl;
    return 0;
}