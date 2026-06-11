#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

using ll = long long;
using P = pair<int, int>;

const ll INF=1e8;
const ll MOD=1e9+7;

int main(int, char**)
{
    int n;
    cin >> n;

    vector<ll> lf(n+1);
    rep(i,n+1) cin >> lf[i];

    vector<ll> acum(n+2,0);
    rep(i,n+1) acum[n-i] = acum[n-i+1] + lf[n-i];

    vector<ll> innd(n+1);
    rep(i,n+1) {
        if (!i) innd[i] = 1;
        else innd[i] = min(acum[0], innd[i-1] * 2);
        innd[i] -= lf[i];
        if (innd[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll ans = 0;
    rep(i,n+1) ans += min(acum[i], innd[i] + lf[i]);

    cout << ans << endl;

    return 0;
}