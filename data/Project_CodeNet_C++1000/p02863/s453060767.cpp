#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, T;
int dp[3010][2][3010];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> T;
    rep(i, N) {
        int A, B; cin >> A >> B;
        rep(j, T) {
            dp[i+1][0][j] = max(dp[i+1][0][j], dp[i][0][j]);
            if (j+A<T) dp[i+1][0][j+A] = max(dp[i+1][0][j+A], dp[i][0][j]+B);
            
            dp[i+1][1][j] = max(dp[i+1][1][j], dp[i][1][j]);
            if (j+A<T) dp[i+1][1][j+A] = max(dp[i+1][1][j+A], dp[i][1][j]+B);
            
            dp[i+1][1][j] = max(dp[i+1][1][j], dp[i][0][j]+B);
        }
    }
    cout << dp[N][1][T-1] << endl;
}