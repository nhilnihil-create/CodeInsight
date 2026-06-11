#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

int main()
{
    ll n;
    cin >> n;
    vector<P> p;
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        p.push_back(P(b, a));
    }
    sort(p.begin(), p.end(), greater<>());
    ll t = p[0].first;
    for (auto v : p)
    {
        // cout << v.first << " " << v.second << endl;
        t = min(t, v.first);
        t -= v.second;
        // cout << t << endl;
    }
    if (t >= 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}