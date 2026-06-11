#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
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

bool isGood(ll n, ll k, const vi &a, const vi &f, ll m){
    ll cnt = 0;
    rep(i, n) cnt += max(0LL, a[i]-(ll)floor(1.0*m/f[i]));
    return (cnt <= k) ? true : false;
}

int main(){
    Init();
    ll n, k; cin >> n >> k;
    vi a(n), f(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(all(a));
    sort(all(f), greater<ll>());

    // 目標スコアを二分探索
    ll r = 10e12 , l=-1;
    while(abs(r-l) > 1){
        ll m = (r+l)/2;
        isGood(n, k, a, f, m) ? r = m : l = m;
    }
    cout << r << endl;
}