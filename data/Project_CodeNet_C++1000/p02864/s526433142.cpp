#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;
const LL LLINF = 1e16;

LL dp[304][304][304];

int main(){
    fastcin();

    int n, K;
    cin >> n >> K;
    vector<int> h(n+1, 0);
    rep(i, n) cin >> h[i+1];
    rep(i, 302)rep(j, 302)rep(k, 302) dp[i][j][k] = LLINF;
    dp[0][0][0] = 0;
    rep(i, n)rep(j, K+1)rep(k, i+1){
        // 高さをa[k]に合わせる
        chmin(dp[i+1][j+1][k], dp[i][j][k]);
        // 高さを変えない
        chmin(dp[i+1][j][i+1], dp[i][j][k]+max(h[i+1]-h[k], 0));
    }
    LL ans = LLINF;
    rep(j, K+1){
        rep(k, n+1){
            chmin(ans, dp[n][j][k]);
            // cout << dp[n][j][k] << " ";
        }
        // cout << endl;
    }
    cout << ans << endl;

}