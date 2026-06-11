#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int INF = 1001001001;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int h, n;
    cin >> h >> n;
    vector<vector<int>> dp(n+1, vector<int>(h+1));
    rep(i,n+1)rep(j,h+1) {
        if (j == 0) dp[i][j] = 0;
        else dp[i][j] = INF;
        //dp[i][j] = INF;
    }
    //dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= h; j++) {
            //chmin(dp[i+1][j], dp[i][j]);
            if (j - a >= 0) chmin(dp[i+1][j], dp[i+1][j-a] + b);
            else chmin(dp[i+1][j], b);
            chmin(dp[i+1][j], dp[i][j]);
        }
    }
    cout << dp[n][h] << endl;
    return 0;
}
