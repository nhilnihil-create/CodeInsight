#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define NINF (ll)-1e18

int main() {
    vector<ll> num1(2), num2(2);
    rep(i, 2) cin >> num1[i];
    rep(i, 2) cin >> num2[i];
    ll ans = NINF;
    rep(i, 2){
        rep(j, 2){
            ll now = num1[i] * num2[j];
            chmax(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}