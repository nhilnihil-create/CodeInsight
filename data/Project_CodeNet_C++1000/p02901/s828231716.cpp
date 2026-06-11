#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using P = pair<long long,long long>;
template <class T> using vec = vector<T>;
template<class T>void sort(vec<T> &v){sort(v.begin(),v.end());}
template<class T>void rsort(vec<T> &v){sort(v.rbegin(),v.rend());}
const ll inf = 99999999999;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m; cin >> n >> m;
    vec<ll> pow2(14); pow2[0] = 1;
    rep(i,13)pow2[i+1] = pow2[i] * 2; 
    ll t = pow2[n];
    vec<ll> dp(5000,inf);
    dp[0] = 0;
    rep(i,m){
        ll a,b; cin >> a >> b;
        ll bit = 0;
        rep(i,b){
            ll c; cin >> c; --c;
            bit += pow2[c];
        }
        rep(i,t){
            ll s = i|bit;
            dp[s] = min(dp[s],dp[i]+a);
        }
    }
    ll ans = dp[t-1] == inf ? -1 : dp[t-1];
    cout << ans << endl;
}