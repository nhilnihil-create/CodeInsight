#include<bits/stdc++.h>
#define QS ios_base::sync_with_stdio(false);
typedef long long ll;
const ll INF = 1e18;
const int MOD = 1e9+7;
using namespace std;


int main(){
//freopen("output.txt", "w", stdout);
    QS
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    ll H[n+2]; H[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> H[i];
    }
    H[n+1] = 0;
    ll dp[n+2][k+2];
    for(int i = 0; i < n + 2; ++i){
        for(int j = 0; j < k + 2; ++j){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i <= n + 1; ++i){
        for(int j = 0; j <= k; ++j){
            for(int _k = 0; _k <= j; ++_k){
                int pos = i - _k - 1;
                if(pos < 0) continue;
                dp[i][j] = min(dp[i][j], dp[pos][j - _k] + max(0LL, H[i]-H[pos]));
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i <= k; ++i){
        ans = min(ans, dp[n+1][i]);
    }
    cout << ans << '\n';
}
