#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<ll, ll>
#define endl "\n"
#define MAXN 100005
using namespace std;

ll h, w, m, a, b;
vector<ll> v, v1;
unordered_map<ll, ll> r, c;
unordered_map<ll, ll> mm;

void solve()
{
    cin >> h >> w >> m;
    ll mr = 0, mc = 0;
    while (m--)
    {
        cin >> a >> b;
        ll t = a * 1e9 + b;
        mm[t]++;
        r[a]++;
        c[b]++;
        mr = max(mr, r[a]);
        mc = max(mc, c[b]);
    }
    for (ll i = 1; i <= h; i++)
    {
        if (r[i] == mr)
            v.pb(i);
    }
    for (ll i = 1; i <= w; i++)
    {
        if (c[i] == mc)
            v1.pb(i);
    }
    ll ans = 0;
    if (v.size() + v1.size() > 3e5)
    {
        cout << mr + mc << endl;
        return;
    }
    for (ll i = 0; i < v.size(); i++)
    {
        for (ll j = 0; j < v1.size(); j++)
        {
            ll t = v[i] * 1e9 + v1[j];
            if (mm[t] == 1)
                ans = max(ans, r[v[i]] + c[v1[j]] - 1);
            else
                ans = max(ans, r[v[i]] + c[v1[j]]);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
