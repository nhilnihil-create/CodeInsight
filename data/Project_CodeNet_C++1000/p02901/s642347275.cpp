#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
const int INF = 999999999;
int main() {
    int n,m; cin >> n >> m;
    int key[1000] = {0};
    int cost[1000] = {0};
    rep(i,m) {
        int a,b; cin >> a >> b;
        cost[i] = a;
        rep(j,b) {
            int t; cin >> t;
            key[i] = key[i] | (1 << (t-1));
        }
    }
    int dp[4096]; rep(i,4096) dp[i] = INF;
    dp[0] = 0;
    rep(k,m) {
        for (int i=pow(2,n)-1; i >= 0; i--) {
            if (dp[i] != INF) {
                dp[i | key[k]] = min(dp[i | key[k]], dp[i] + cost[k]);
            }
        }
    }
    int ans = dp[(int)pow(2,n)-1];
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}