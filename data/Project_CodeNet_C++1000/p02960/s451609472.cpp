#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[100005][15];
signed main() {
    string S;
    cin >> S;
    dp[S.size()][0] = 1;
    int pow = 1;
    for(int i = S.size()-1; i >= 0; i--) {
        if(S[i] != '?') {
            for(int j = 0; j <= 12; j++) {
                if(dp[i+1][j]) {
                    dp[i][(j+(S[i]-'0')*pow)%13]+=dp[i+1][j];
                    dp[i][(j+(S[i]-'0')*pow)%13]%=INF;
                }
            }
        }
        else {
            for(int j = 0; j <= 12; j++) {
                if(dp[i+1][j]) {
                    for(int k = 0; k <= 9; k++) {
                        dp[i][(j+k*pow)%13]+=dp[i+1][j];
                        dp[i][(j+k*pow)%13]%=INF;
                    }
                }
            }
        }
        pow *= 10;
        pow %= 13;
    }
    cout << dp[0][5] << endl;
}