#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
ll n;
cin>>n;
vector<vector<pair<ll,ll>>> testify(n);
for(ll i=0;i<n;i++){
    ll a;
    cin>>a;
    testify[i].resize(a);
    for(ll j=0;j<a;j++){
        ll x,y;
        cin >> x >> y;
        x--;
        testify[i][j].first = x;
        testify[i][j].second = y;
    }
}
int ans = 0;
for (ll bit = 0; bit < (1 << n); bit++){
    bool flag = true;
    for (ll i = 0; i < n; i++) {
        if (!(bit & (1 << i))) continue;
        for(auto k:testify[i]){
            if (k.second && !(bit & (1 << k.first))) flag = false;
            if (!(k.second) && (bit & (1 << k.first))) flag = false;
        }
    }
    if (flag)chmax(ans, __builtin_popcountl(bit));
}
cout << ans << endl;
}