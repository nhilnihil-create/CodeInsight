#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

signed main() {
    int N, T; cin >> N >> T;
    int A[N], B[N];
    rep(i, N) cin >> A[i] >> B[i];
    int dp[N+1][T][2];
    rep(i, N+1) rep(j, T) rep(k, 2) dp[i][j][k] = 0;
    
    rep(i, N) {
        rep(j, T) {
            dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][0]);
            dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][1]);
            dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][0]+B[i]);
            
            if (j+A[i]<T) {
                dp[i+1][j+A[i]][0] = max(dp[i+1][j+A[i]][0], dp[i][j][0]+B[i]);
                dp[i+1][j+A[i]][1] = max(dp[i+1][j+A[i]][1], dp[i][j][1]+B[i]);
            }
        }
    }
    
    cout << dp[N][T-1][1] << endl;
}