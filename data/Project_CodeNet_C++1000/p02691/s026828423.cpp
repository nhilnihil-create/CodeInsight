#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)

using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    ll ans = 0;
    REP(i, n)
    {
        cin >> a[i];
        ans += mp[i - a[i]];
        mp[i + a[i]] += 1;
    }
    cout << ans << endl;
}

signed main()
{
    solve();
}