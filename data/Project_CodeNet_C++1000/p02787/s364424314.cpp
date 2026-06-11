#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int dp[1005][10005];

int main() {
    int h, n;
    cin >> h >> n;
    rep(i,n+1)rep(j,h+1) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        rep(j,h+1) {
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][min(j+a,h)], dp[i+1][j] + b);
        }
    }
    cout << dp[n][h] << endl;
    return 0;
}