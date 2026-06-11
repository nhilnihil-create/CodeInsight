#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const ll MOD = 1000000007;
using namespace std;

int main(void)
{
    ll n;
    cin >> n;
    map<ll, ll> v;
    vector<ll> x;
    rep(i, 0, n)
    {
        ll tmp;
        cin >> tmp;
        x.push_back(tmp);
        v[tmp]++;
    }
    ll ans = 0;
    for (auto i : v)
    {
        if (i.second != 0)
            ans += (i.second) * (i.second - 1) / 2;
    }
    rep(i, 0, n)
    {
        if (v[x[i]] > 0)
            cout << ans - v[x[i]] + 1 << endl;
        else
            cout << ans << endl;
    }
}
