#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
    ll n, ans = 0, cnt = 0;
    cin >> n;
    ll h[n];
    rep(i, n) cin >> h[i];
    rep(i, n - 1)
    {
        if (h[i] >= h[i + 1])
            cnt++;
        if (h[i] < h[i + 1] || i == n - 2)
        {
            // cout << h[i] << h[i + 1] << endl;
            if (cnt > ans)
                ans = cnt;

            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}