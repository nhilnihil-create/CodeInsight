#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll INF = 1LL<<60;

void chmin(ll &a, ll b){
    a = min(a, b);
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> h(N+2);
    for(int i=0;i<N;i++){
        cin >> h[i+1];
    }
    vector<vector<ll> > dp(N+2, vector<ll>(K+1,INF));
    dp[0][0] = 0;
    for(int i=0;i<N+1;i++){
        for(int j=0;j<=K;j++){
            chmin(dp[i+1][j], dp[i][j] + max(h[i+1]-h[i], 0LL));
            for(int k=1;j+k<=K&&i+k<=N;k++){
                chmin(dp[i+k+1][j+k], dp[i][j] + max(h[i+k+1]-h[i],0LL));
            }
        }
    }
    cout << dp[N+1][K] << endl;
    return 0;
}
