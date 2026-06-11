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

int main(){
    Init();
    ll n, t; cin >> n >> t;
    vector<pair<ll, ll>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    sort(all(ab));

    // dp[i][j]; i番目の料理まででj分までに完食できる美味しさの最大値（i番目の料理はt-1時点で注文する）
    vvi dp(n+1, vi(t+1, 0));

    rep(i, n){
        rep(j, t){
            chmax(dp[i+1][j], dp[i][j]);
            if(ab[i].first <= j){
                chmax(dp[i+1][j], dp[i][j-ab[i].first]+ab[i].second);
            }
            if(j == t-1) dp[i][j] += ab[i].second;
        }
    }
    ll ans = 0;
    rep(i, n) chmax(ans, dp[i][t-1]);
    cout << ans << endl;
}