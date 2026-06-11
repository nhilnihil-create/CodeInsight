#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
ll solver(ll h, ll w, ll m, set<pair<ll, ll>> &st)
{
    ll sh[h] = {}, sw[w] = {};
    for (auto x : st)
    {
        ++sh[x.first], ++sw[x.second];
    }
    ll maxh = 0, maxw = 0;
    rep(i, 0, h)
    {
        if (sh[i] > maxh)
            maxh = sh[i];
    }
    rep(i, 0, w)
    {
        if (sw[i] > maxw)
            maxw = sw[i];
    }
    vector<ll> ih, iw;
    rep(i, 0, h)
    {
        if (sh[i] == maxh)
        {
            ih.push_back(i);
        }
    }
    rep(i, 0, w)
    {
        if (sw[i] == maxw)
        {
            iw.push_back(i);
        }
    }
    ll ans = maxh + maxw;
    rep(i, 0, ih.size())
    {
        rep(j, 0, iw.size())
        {
            if (st.count(make_pair(ih[i], iw[j])) == 0)
            {
                return ans;
            }
        }
    }
    return ans - 1;
}

int main()
{
    ll h, w, m;
    cin >> h >> w >> m;
    set<pair<ll, ll>> st;
    ll tmph, tmpw;
    rep(i, 0, m)
    {
        cin >> tmph >> tmpw;
        --tmph, --tmpw;
        st.insert(make_pair(tmph, tmpw));
    }
    cout << solver(h, w, m, st) << endl;
}