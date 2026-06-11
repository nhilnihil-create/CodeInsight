#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    vector<ll> p_cum(n+1, 0);
    rep(i, n){
        cin >> p[i];
        p_cum[i+1] = p_cum[i] + p[i];
    }

    ll ma_a = 0;
    rep(i, n-k+1){
        ll tmp = p_cum[i+k] - p_cum[i];
        ma_a = max(tmp, ma_a);
    }
    double ans = double((ma_a+k))/2.0;
    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}
