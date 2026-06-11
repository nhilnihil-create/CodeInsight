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
    ll n, d;
    cin >> n >> d;
    vector<vector<ll>> x(n, vector<ll>(d));
    rep(i, n)
    {
        rep(j, d)
        {
            cin >> x[i][j];
        }
    }
    ll ans = 0;
    rep(i, n)
    {
        rep2(j, i + 1, n)
        {
            ll now = 0;
            rep(k, d)
            {
                now += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            rep(k, 200)
            {
                if (k * k == now)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}