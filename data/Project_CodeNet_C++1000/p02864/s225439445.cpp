#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N, K; cin >> N >> K;
    vector<ll> H(N+5,0);
    REP(i,N) cin >> H[i+1];
    ll dp[N+5][K+1];
    REP(i,N+5)REP(j,K+1) dp[i][j] = INF;
    REP(j,K+1)dp[0][j] = 0;
    REP(i,N+5)REP(j,K+1){
        REP(l,K+1){
            if(i+l+1<=N+4 && j+l<=K && dp[i][j] != INF) {
                dp[i+l+1][j+l] = min(dp[i+l+1][j+l], dp[i][j]+max(0LL,H[i+l+1]-H[i]));
            }
        }
    }
    ll ans = INF;
    REP(i,K+1) ans = min(ans, dp[N+1][i]);
    cout << ans << endl;
    return 0;
}