#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a.at(i);
    ll ans = 0;
    ll maxval = 0;
    rep(i, n){
        chmax(maxval, a.at(i));
        ans += maxval - a.at(i);
    }
    cout << ans << endl;
}