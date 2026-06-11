#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
ll siz(ll n)
{
    ll now = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            now++;
            if (i != n / i)
            {
                now++;
            }
        }
    }
    return now;
}
vector<ll> div(ll n)
{
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i)
            {
                res.push_back(n / i);
            }
        }
    }
    return res;
}
int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ans += siz(n - 1) - 1;
    vector<ll> a = div(n);
    rep2(i, 1, a.size())
    {
        ll m = n;
        while (m % a[i] == 0)
        {
            m /= a[i];
        }
        if (m % a[i] == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
}