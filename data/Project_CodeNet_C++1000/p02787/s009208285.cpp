#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(a,b) a = min(a,b);

int dp[1005][10005];
const int INF = 1001001001;

int main() {
    int h, n;
    cin >> h >> n;
    rep(i,1005)rep(j,10005) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n) dp[i][0] = 0;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        rep(j,h+1) {    
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][min(j+a, h)], dp[i+1][j] + b);
        }
    }
    cout << dp[n][h] << endl;
    return 0;
}