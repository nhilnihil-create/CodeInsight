#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
int main()
{
    ll n, m;
    cin >> n >> m;
    set<ll> d;
    string s;
    cin >> s;
    rep(i, n + 1)
    {
        if (s[i] == '1')
        {
            d.insert(i);
        }
    }
    ll now = 0;
    rep(i, n + 1)
    {
        if (s[i] == '0')
        {
            if (i - now > m)
            {
                cout << -1 << endl;
                return 0;
            }
            now = i;
        }
    }
    now = n;
    vector<ll> ans;
    while (now - m > 0)
    {
        rep2(i, now - m, now)
        {
            if (!d.count(i))
            {
                ans.push_back(now - i);
                now = i;
            }
        }
    }
    ans.push_back(now);
    for (ll i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}