#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
    int N, W;
    cin >> N >> W;
    int v[N], w[N];
    REP(i, N) cin >> v[i] >> w[i];
    int dp[N+1][W+1] = {};
    int res = 0;
    REP(i, N){
        REP(j, W+1){
            if(j<w[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}