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
    ll to = 0;
    rep(i, n)
    {
        cin >> a[i];
        to += a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<ll> b(n);
    rep(i, n)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    if (to <= k)
    {
        cout << 0 << endl;
        return 0;
    }
    ll l = 0;
    ll r = 0;
    rep(i, n)
    {
        r = max(r, a[i] * b[i]);
    }

    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        ll now = 0;
        rep(i, n)
        {
            if (a[i] * b[i] > mid)
            {
                now += (a[i] * b[i] - mid - 1) / b[i] + 1;
            }
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