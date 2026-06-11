#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    ll n;
    cin >> n;
    vector<int>x(n);
    rep(i, n) cin >> x[i];
    ll ans = 1e15;
    rep(p, 101){
        ll sum = 0;
        rep(i, n){
            sum += (x[i] - p)*(x[i] - p);
        }
        ans = min(sum, ans);
    }
    cout << ans << endl;
    return 0;
}
