#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[2005][2005];
signed main() {
    int N,M;
    cin >> N >> M;
    vector<int>S(N+1),T(M+1);
    for(int i = 1; i <= N; i++) {
        cin >> S[i];
    }
    for(int i = 1; i <= M; i++) {
        cin >> T[i];
    }
    for(int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }
    for(int i = 0; i <= M; i++) {
        dp[0][i] = 1;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(S[i] == T[j]) {
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i][j-1]+dp[i-1][j]+mod-dp[i-1][j-1];
            }
            dp[i][j]%=mod;
        }
    }
    cout << dp[N][M] << endl;
}