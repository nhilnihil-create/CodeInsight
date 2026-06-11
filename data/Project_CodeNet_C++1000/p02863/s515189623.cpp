#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[3005][3005];
signed main() {
    int N,T;
    cin >> N >> T;
    vector<P>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(),A.end());
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            dp[i][A[i].first] = A[i].second;
            continue;
        }
        for(int j = 0; j < T; j++) {
            dp[i][min(T,j+A[i].first)] = max(dp[i][min(T,j+A[i].first)],dp[i-1][j]+A[i].second);
        }
        for(int j = 0; j < 3005; j++) {
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    int ans = 0;
    for(int i = 0; i < 3005; i++) {
        ans = max(ans,dp[N-1][i]);
    }
    cout << ans << endl;
}