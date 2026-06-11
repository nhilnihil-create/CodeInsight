#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    double ans = (v[0] + v[1])*0.5;
    for (int i = 2;  i < n; i++) {
        ans = (ans + v[i])*0.5;
    }
    cout << setprecision(15) << ans << endl;
    return 0;
}
