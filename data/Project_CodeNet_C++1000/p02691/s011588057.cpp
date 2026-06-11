#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;


int main() {
    int n; cin >> n;
    map<ll, ll> mp, mm;
    rep(i, n) {
        ll a; cin >> a;
        if(!mp.count(i+a)) mp[i+a] = 1;
        else mp[i+a]++;
        if(!mm.count(i-a)) mm[i-a] = 1;
        else mm[i-a]++;
    }
    ll ans = 0;
    map<ll, ll> sum;
    for(auto x : mp) {
        if(!sum.count(x.first)) sum[x.first] = x.second;
        else sum[x.first] += x.second;
    }
    for(auto x : mm) {
        if(!sum.count(x.first)) sum[x.first] = x.second;
        else sum[x.first] += x.second;
    }
    for(auto x : sum) if(x.second > 1) ans += mp[x.first] * mm[x.first];
    cout << ans << endl;
}
