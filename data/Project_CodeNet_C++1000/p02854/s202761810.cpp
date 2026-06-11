#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i){
        a[i] += a[i-1];
    }
    ll ans = 1e18;
    rep(i,n-1) {
        ll r = a[n-1] - a[i];
        ll l = a[i];
        ans = min(ans, abs(r-l));
    }
    cout << ans << endl;
    return 0;
}