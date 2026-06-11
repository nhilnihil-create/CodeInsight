#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
ll ch(ll n)
{
    ll r = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        r++;
    }
    return r;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    ll k = ch(a[0]);
    rep(i, n)
    {
        if (k != ch(a[i]))
        {
            cout << 0 << endl;
            return 0;
        }
        ll K = k;
        while (K--)
        {
            a[i] /= 2;
        }
    }
    ll now = a[0];
    rep(i, n)
    {
        if (now * (ll)pow(2LL, k - 1) > m)
        {
            cout << 0 << endl;
            return 0;
        }
        now = now * a[i] / __gcd(now, a[i]);
    }
    now *= (ll)pow(2LL, k - 1);
    cout << m / now - m / (2 * now) << endl;
}