#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll mod = 998244353;

    ll n;
    cin >> n;

    vector<ll> d(n);
    vector<ll> d_cnt(n, 0);

    rep(i, n)
    {
        cin >> d.at(i);
        d_cnt.at(d.at(i))++;
    }

    ll ans = (d_cnt.at(0) == 1);
    for (int i = 1; i < n; i++)
    {
        ll dist = d.at(i);
        if (dist == 0)
        {
            ans = 0;
        }
        else
        {
            ans *= d_cnt.at(dist - 1);
        }
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}