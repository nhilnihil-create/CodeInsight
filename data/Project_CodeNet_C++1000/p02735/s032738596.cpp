#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
int dp[105][105][2];
signed main() {
    int H,W;
    cin >> H >> W;
    vector<string>S(H);
    for(int i = 0; i < H; i++) {
        cin >> S[i];
    }
    for(int i = 0; i < 105; i++) {
        for(int j = 0; j < 105; j++) {
            for(int k = 0; k < 2; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    if(S[0][0] == '#') {
        dp[0][0][1] = 1;
    }
    else {
        dp[0][0][0] = 0;
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(dp[i][j][0] != INF) {
                if(i+1 < H) {
                    if(S[i+1][j] == '#') dp[i+1][j][1] = min(dp[i+1][j][1],dp[i][j][0]+1);
                    else dp[i+1][j][0] = min(dp[i+1][j][0],dp[i][j][0]);
                }
                if(j+1 < W) {
                    if(S[i][j+1] == '#') dp[i][j+1][1] = min(dp[i][j+1][1],dp[i][j][0]+1);
                    else dp[i][j+1][0] = min(dp[i][j+1][0],dp[i][j][0]);
                }
            }
            if(dp[i][j][1] != INF) {
                if(i+1 < H) {
                    if(S[i+1][j] == '#') dp[i+1][j][1] = min(dp[i+1][j][1],dp[i][j][1]);
                    else dp[i+1][j][0] = min(dp[i+1][j][0],dp[i][j][1]);
                }
                if(j+1 < W) {
                    if(S[i][j+1] == '#') dp[i][j+1][1] = min(dp[i][j+1][1],dp[i][j][1]);
                    else dp[i][j+1][0] = min(dp[i][j+1][0],dp[i][j][1]);
                }
            }
        }
    }
    cout << min(dp[H-1][W-1][0],dp[H-1][W-1][1]) << endl;
}
