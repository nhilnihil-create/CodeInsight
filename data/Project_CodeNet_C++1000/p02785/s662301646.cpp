#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int>h(n);
    ll ans = 0;
    rep(i, n) {
        cin >> h[i];
        ans += h[i];
    }
    sort(h.begin(), h.end(), greater<int>());
    rep(i, min(k,n)){
        ans -= h[i];
    }
    
    cout << ans << endl;
    return 0;
}
