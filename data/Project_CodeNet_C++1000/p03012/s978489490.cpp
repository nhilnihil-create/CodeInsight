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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll now = 0;
    rep(i, n)
    {
        cin >> a[i];
        now += a[i];
    }
    ll ans = now;
    rep(i, n)
    {
        now -= 2 * a[i];
        ans = min(ans, abs(now));
    }
    cout << ans << endl;
}