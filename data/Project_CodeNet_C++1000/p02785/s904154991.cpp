
#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(void) {
    io;
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(),v.end());
    rep(i,k){
        v.pop_back();
    }
    int rem = v.size();
    ll ans = 0;
    rep(i,rem) {
        ans += v[i];
    }
    cout << ans;
    return 0;
}
