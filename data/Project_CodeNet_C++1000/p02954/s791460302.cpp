#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[35][101010];
int ans[101010];
signed main() {
    string S;
    cin >> S;
    int N = S.size();
    for(int i = 0; i < N; i++) {
        if(S[i] == 'R') {
            dp[0][i] = i+1;
        }
        else {
            dp[0][i] = i-1;
        }
    }
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < N; j++) {
            dp[i+1][j] = dp[i][dp[i][j]];
        }
    }
    for(int i = 0; i < N; i++) {
        ans[dp[32][i]]++;
    }
    for(int i = 0; i < N; i++) {
        if(i) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
}