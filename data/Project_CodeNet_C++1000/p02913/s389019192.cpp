#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
const int INF = numeric_limits<int>::max() / 2;
typedef pair<int,int> P;


signed main() {
    int N;
    string S;
    cin >> N >> S;

    int dp[N+1][N+1]{};
    int ans = 0;

    rep(i,N){
        rep(j,N){
            if(S[i] == S[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                dp[i+1][j+1] = min(dp[i+1][j+1], abs(j-i));
                ans = max(ans, dp[i+1][j+1]);
            }
        }
    }
    cout << ans << endl;
}