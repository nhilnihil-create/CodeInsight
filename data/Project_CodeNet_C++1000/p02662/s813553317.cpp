#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[3005][3005];
signed main() {
    int N,S;
    cin >> N >> S;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    dp[0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= S; j++) {
            dp[i+1][j] += dp[i][j]*2;
            if(j+A[i] <= S) {
                dp[i+1][j+A[i]] += dp[i][j];
            }
            dp[i+1][j] %= mod;
        }
    }
    cout << dp[N][S] << endl;
}