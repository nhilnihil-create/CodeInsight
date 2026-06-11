#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

int main()
{
    ll n, ans = 100000;
    cin >> n;
    ll s[n], sum = 0;
    rep(i, n)
    {
        ll w;
        cin >> w;
        sum += w;
        s[i] = sum;
    }
    rep(i, n - 1)
    {
        ans = min(ans, abs(s[n - 1] - 2 * s[i]));
    }

    cout << ans << endl;
    return 0;
}