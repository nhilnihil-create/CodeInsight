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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    ll l = 0;
    ll r = 1000000000;

    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        ll now = 0;
        rep(i, n)
        {
            now += (a[i] - 1) / mid;
        }
        if (k >= now)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r << endl;
}