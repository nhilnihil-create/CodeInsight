#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll x = 0;
    rep(i,n) {
        if (i%2) x -= a[i];
        else x += a[i];
    }
    vector<ll> ans(n);
    ans[0] = x/2;
    for (int i = 1; i <= n-1; i++) {
        ans[i] = a[i-1] - ans[i-1];
    }
    rep(i,n) ans[i] *= 2;
    rep(i,n) cout << ans[i] << endl;
    return 0;
}