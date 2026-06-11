#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    int n, m;
    cin >> n >> m;
    int b, c_tmp;
    vector<int> a(m);
    vector<int> c(m);
    rep(i,m) {
        cin >> a[i] >> b;
        rep(j,b) {
            cin >> c_tmp;
            c_tmp--;
            c[i] += (1 << c_tmp);
        }
    }
    vector<vector<int>> dp(m, vector<int>(1 << n, INF));
    rep(i,1 << n) {
        if (i == 0) {dp[0][i] = 0; continue;}
        if ((i & ~c[0]) == 0) dp[0][i] = a[0];
    }
    rep(i,m-1) {
        rep(j,1 << n) {
            if (j == 0) {dp[i+1][j] = 0; continue;}
            dp[i+1][j] = min(dp[i][j], dp[i][j & ~c[i+1]] + a[i+1]);
        }
    }
    int ans = (dp[m-1][(1 << n) - 1] == INF ? -1 : dp[m-1][(1 << n) - 1]);
    cout << ans << endl;
    return 0;
}