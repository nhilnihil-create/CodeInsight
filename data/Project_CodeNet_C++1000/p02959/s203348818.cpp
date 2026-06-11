#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    rep(i, n + 1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, n)
    {
        ans += min(a[i], b[i]);
        b[i] -= min(a[i], b[i]);
        ans += min(a[i + 1], b[i]);
        a[i + 1] -= min(a[i + 1], b[i]);
    }
    cout << ans << endl;
    return 0;
}