#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n, k, h[300000], ans = 0;
    cin >> n >> k;
    rep(i, n) cin >> h[i];
    sort(h, h + n, greater());
    for (int i = k; i < n; i++)
        ans += h[i];
    cout << ans << endl;
    return 0;
}