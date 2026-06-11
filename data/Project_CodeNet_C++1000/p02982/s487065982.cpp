#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

int main()
{
    ll n, d, ans = 0;
    cin >> n >> d;
    ll x[n][d];
    rep(i, n) rep(j, d) cin >> x[i][j];

    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = i+1; j < n; j++)
        {
            double dist = 0;
            for (ll k = 0; k < d; k++)
            {
                dist += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            if (ceil(sqrt(dist)) == floor(sqrt(dist)))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}