#include <bits/stdc++.h>
#define rep(i, n) for (ll(i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<int> ans(n, 0);
    vp s(m);
    rep(i, m)
    {
        cin >> s[i].first >> s[i].second;
    }
    sort(s.begin(), s.end());
    rep(i, m - 1)
    {
        if (s[i].first == s[i + 1].first && s[i].second != s[i + 1].second)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    rep(i, m)
    {
        if (s[i].first == 1 && s[i].second == 0 && n != 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if (n > 1)
    {
        ans[0] = 1;
    }
    rep(i, m)
    {
        ans[s[i].first - 1] = s[i].second;
    }
    rep(i, n)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}