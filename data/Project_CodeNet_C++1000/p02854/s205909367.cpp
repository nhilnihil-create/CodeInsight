#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) a[i] = a[i - 1] + a[i];
    ll ans = 1e18;
    for (int i = 0; i + 1 < n; i++)
    {
        ll x = a[i], y = a[n - 1] - a[i];
        ans = min(ans, abs(x - y));
    }
    cout << ans;
}
