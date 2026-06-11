#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

int main()
{
    ll l, r, ans = 2018 * 2018;
    cin >> l >> r;
    if (r - l >= 2019)
        ans = 0;
    l %= 2019;
    r %= 2019;
    if (l > r)
    {
        ll tmp = l;
        l = r;
        r = tmp;
    }
    for (ll i = l; i <= r - 1; i++)
    {
        for (ll j = i + 1; j <= r; j++)
        {
            ans = min(ans, (i * j) % 2019);
        }
    }
    cout << ans << endl;
    return 0;
}