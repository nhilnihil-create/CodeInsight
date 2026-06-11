#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

const int INF = 1001001001;
int dp[1005][10005];

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    rep(i,n+1) rep(j,h+1) dp[i][j] = INF;

    dp[0][0] = 0;

    rep(i,n) rep(j,h+1){
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        int nj = min(h, j + a[i]);
        dp[i+1][nj] = min(dp[i+1][nj], dp[i+1][j] + b[i]);
    }

    cout << dp[n][h] << endl;
}