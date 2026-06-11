#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define print(x) cout << x << endl
#define prints(x) cout << x << " "
#define printline cout << endl

bool comp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    return a.second > b.second;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    ll h, w, m;
    cin >> h >> w >> m;
    set<pair<ll, ll>> s;
    vector<ll> H(3e5, 0);
    vector<ll> W(3e5, 0);
    for (ll i = 0; i < m; i++)
    {
        ll r, c;
        cin >> r >> c;
        r--;
        c--;
        H[r]++;
        W[c]++;
        s.insert({r, c});
    }

    ll ans = 0;
    vector<pair<ll, ll>> hp;
    vector<pair<ll, ll>> wp;
    for (ll i = 0; i < 3e5; i++)
    {
        if (H[i])
            hp.push_back({i, H[i]});
        if (W[i])
            wp.push_back({i, W[i]});
    }
    sort(hp.begin(), hp.end(), comp);
    sort(wp.begin(), wp.end(), comp);
    // for (ll i = 0; i < hp.size(); i++)
    // {
    //     prints(hp[i].second);
    // }printline;
    // for (ll i = 0; i < wp.size(); i++)
    // {
    //     prints(wp[i].second);
    // }printline;
    ll mh = hp[0].second;
    ll mw = wp[0].second;
    ans = mh + mw - 1;
    for (ll i = 0; i < (ll)hp.size(); i++)
    {
        if (hp[i].second != mh)
            break;
        int found=0;
        for (ll j = 0; j < (ll)wp.size(); j++)
        {
            if (wp[j].second != mw)
                break;
            ll temp = hp[i].second + wp[j].second;
            if (s.find({hp[i].first, wp[j].first}) != s.end())
            {
                temp--;
            }
            else
            {
                ans++;
                found=1;
                break;
            }

            ans = max(ans, temp);
        }
        if(found)break;
    }
    print(ans);
    return 0;
}