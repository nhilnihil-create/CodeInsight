#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n, ans = 0;
    cin >> n;
    ll a[n], b[n], c[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n - 1) cin >> c[i];

    rep(i, n)
    {
        ans += b[a[i] - 1];
        if (i == 0)
            continue;
        if (a[i] == a[i - 1] + 1)
            ans += c[a[i - 1] - 1];
    }
    cout << ans << endl;
    return 0;
}