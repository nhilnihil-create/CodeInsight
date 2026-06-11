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
    ll h, w; cin >> h >> w;
    vector<string> s(h);
    for(long long i=0; i<h; i++) cin >> s[i];
    // w->bに移動する際にコスト1かかるものとしてdp
    vvi dp(h, vi(w, 10001));
    dp[0][0] = (s[0][0] == '.' ? 0 : 1);
    for(long long i=0; i<h; i++){
        for(long long j=0; j<w; j++){
            // 現在見ているマスが黒の場合
            if(s[i][j] == '#'){
                // 一つ前が白か黒かで場合分け
                if(i > 0) chmin(dp[i][j], dp[i-1][j] + (s[i-1][j] == '.' ? 1 : 0));
                if(j > 0) chmin(dp[i][j], dp[i][j-1] + (s[i][j-1] == '.' ? 1 : 0));
            }
            else{
                if(i > 0) chmin(dp[i][j], dp[i-1][j]);
                if(j > 0) chmin(dp[i][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
}