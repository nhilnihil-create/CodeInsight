#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

vector<ll> divisors(ll n){
    vector<ll> ret;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            ret.push_back(i);
            if(i * i != n)ret.push_back(n/i);
        }
    }
    sort(all(ret));
    return ret;
}

int main() {
    ll n, k, ans;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    for(auto x : divisors(accumulate(all(a), 0LL))){
        vector<ll> b(n); 
        ll ok = false, sum1 = 0, sum2 = 0;
        rep(i, n)b[i] = a[i] % x; 
        rep(i, n)sum1 += (x-b[i]) % x; sort(all(b));
        rep(i, n){
            if(max(sum1, sum2) <= k)ok = true;
            sum1 -= (x-b[i]) % x;
            sum2 += b[i];
        }
        if(ok)ans = x;
    }
    cout << ans << endl;
}