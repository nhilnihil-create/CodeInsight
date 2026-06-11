#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
ll mod = 1e9+7;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll c = 0;
    rep(i,n){
        for(int j = i; j < n; ++j) {
            if(a[i] > a[j]) c++;
        }
    }
    ll ans = c*k%mod;

    ll d = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i] > a[j]) d++;
        }
    }
    ans += k*(k-1)/2%mod * d%mod;
    ans%=mod;
    cout << ans << endl;
    return 0;
}
