#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<ll, ll>;

int main()
{
    ll n, d, a;
    cin >> n >> d >> a;

    vector<pint> xh(n);
    rep(i, n) cin >> xh[i].first >> xh[i].second;
    rep(i, n) xh[i].second = (xh[i].second % a == 0) ? xh[i].second / a : xh[i].second / a + 1;

    sort(xh.begin(), xh.end());

    vector<ll> pos;
    vector<pint> num;
    ll ans = 0;
    rep(i, n)
    {
        ll &x = xh[i].first;
        ll &h = xh[i].second;

        ll l = upper_bound(pos.begin(), pos.end(), x - d - 1) - pos.begin();
        if (l != (ll)pos.size())
        {
            h = h - (ans - num[l].second);
            if (h <= 0)
                continue;
        }

        pos.emplace_back(x + d);
        ll tmp = ans;
        ans += h;
        num.emplace_back(pint(ans, tmp));
    }
    cout << ans << endl;
}