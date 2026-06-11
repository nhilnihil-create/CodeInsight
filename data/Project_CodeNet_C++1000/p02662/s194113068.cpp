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

int main(){
    Init();
    ll n, s; cin >> n >> s;
    vi a(n);
    rep(i, n) cin >> a[i];
    vvi dp(n+1, vi(s+1, 0));
    dp[0][0] = 1;

    for(ll i=1; i<=n; i++){
        for(ll j=0; j<=s; j++){
            dp[i][j] = (dp[i][j]+dp[i-1][j]*2)%MODV;
            if(j+a[i-1] <= s){
                dp[i][j+a[i-1]] = (dp[i][j+a[i-1]]+dp[i-1][j])%MODV;
            }
        }
    }
    cout << dp[n][s] << endl;
}