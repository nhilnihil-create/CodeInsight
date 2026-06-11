#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
ll MOD = 1e9 + 7;
int main() {
    ll n, a, b, c, ans, s;
    cin >> n;
    vector<ll>x(n), y(n), d(n);
    rep(i, n) cin >> x[i] >> y[i];
    ll mi,ma;
    mi = 3e9;
    ma = 0;
    rep(i, n) {
        d[i] = x[i]+y[i];
        if (d[i] < mi) {
            mi = d[i];
        }
        if (d[i] > ma) {
            ma = d[i];
        }
    }
    b = ma - mi;
    mi = 3e9;
    ma = -3e9;
    rep(i, n) {
        d[i] = x[i]-y[i];
        if (d[i] < mi) {
            mi = d[i];
        }
        if (d[i] > ma) {
            ma = d[i];
        }
    }
    c = ma - mi;
    cout << max(b,c) << endl;
    return 0;
}

