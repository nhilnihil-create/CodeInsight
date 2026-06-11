#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[100005][2];
signed main() {
    string L;
    cin >> L;
    dp[0][0] = 1;
    dp[0][1] = 2;
    for(int i = 1; i < L.size(); i++) {
        if(L[i] == '1') {
            dp[i][1] = dp[i-1][1]*2;
            dp[i][0] = dp[i-1][0]*3+dp[i-1][1];
            dp[i][1] %= mod;
            dp[i][0] %= mod;
        }
        else {
            dp[i][1] = dp[i-1][1];
            dp[i][0] = dp[i-1][0]*3%mod;
        }
    }
    cout << (dp[L.size()-1][0]+dp[L.size()-1][1])%mod << endl;
}
