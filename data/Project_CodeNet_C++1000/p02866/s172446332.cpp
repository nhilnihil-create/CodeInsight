#include <bits/stdc++.h>
#define ll long long
#define MODV 998244353
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

long long modPow(long long x, long long n, long long mod = MODV){
    if(n == 0) return 1;
    if(n%2 == 0) return modPow(x*x%mod, n/2, mod)%mod;
    return x%mod * modPow(x%mod, n-1, mod)%mod;
}

int main(){
    Init();
    ll n, md = 0; cin >> n;
    vi d(n);
    map<ll, ll> cnt;
    rep(i, n){
        cin >> d[i];
        cnt[d[i]]++;
        chmax(md, d[i]);
    }
    // 根が1個以外だとダメ
    if(cnt[0] != 1 || d[0] != 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    ll sum = 0;
    for(ll i=0; i<md; i++){
        sum += cnt[i];
        ans *= modPow(cnt[i], cnt[i+1]);
        ans %= MODV;
    }
    cout << ans << endl;
}