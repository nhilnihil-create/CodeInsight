#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll mod = (ll)1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    ll ans = 0;
    rep(i,60){
        ll x = 0;
        rep(j,n)if(a.at(j)>>i & 1) x++;
        ll y = (ll)n - x;
        ll now =  x * y % mod;
        rep(k,i) now = now * 2 % mod;
        ans += now;
        ans %= mod;
    }
    cout << ans << endl;
    // ll ans = 0;
    // for(int i = 0;i < n -1;i++){
    //     for(int j = i + 1; j < n;j++){
    //         ll t = (a.at(i)) ^ (a.at(j));
    //         t %= MX;
    //         ans = (ans + t) % MX;
    //     }
    // }
    // cout << ans << endl;
}