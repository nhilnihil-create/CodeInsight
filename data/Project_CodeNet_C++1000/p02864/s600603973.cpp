#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<=b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<=a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;

ll dp[305][305];
ll pre[305][305];
int main(){
    ll n,k; cin >> n >> k;
    vector<ll> h(n+1);
    for(int i=1; i<=n; i++) cin >>h[i];

    rep(i,305)rep(j,305) dp[i][j]=INF;
    rep(i,305)rep(j,305) pre[i][j]=0;
    dp[0][0] = 0;
    pre[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n-k; j++){
            if(j+1>i) continue;
            // //i+1番目まで見てj個選ぶときの最小コストをi番目まで見てj個選ぶときの最小コストで更新。
            // //更新できたなら、i+1番目まで見てj個選ぶときに最小コストを叩き出す組み合わせで一番右にあるのはi番目まで見てj個選ぶときと同じ。（何も加えてないので）
            // if(chmin(dp[i+1][j], dp[i][j])) pre[i+1][j] = pre[i][j]; 
            // //i+1番目まで見てj+1個選ぶときの最小コストをi番目まで見てj個選んだときの最小コスト+その際の一番右の柱を参考にしたコストとして更新
            // if(chmin(dp[i+1][j+1], dp[i][j]+max(h[i+1]-pre[i][j],(ll)0))) pre[i+1][j+1] = h[i+1];
            rep(k,i){
                chmin(dp[i][j+1], dp[k][j]+max((ll)0, h[i]-h[k]));
            }

        }
    }
    ll ans = INF;
    rep(i,n+1) chmin(ans, dp[i][n-k]);
    cout << ans << endl;
    
    return 0;
}