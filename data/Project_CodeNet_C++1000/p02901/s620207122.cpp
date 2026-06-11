#include <bits/stdc++.h>

//#define int long long

using namespace std;

int dp[1001][1<<13];
int cost[1001];
int boxes[1001];

int n, m;

int recur(int pos, int mask) {
    if (mask == (1<<n)-1) return 0;
    if (pos == m) return 1e9;
    if (dp[pos][mask] != -1) return dp[pos][mask];
    int res = min(recur(pos+1, mask), recur(pos+1, mask|boxes[pos]) + cost[pos]);
    dp[pos][mask] = res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 1001; i++) {
        cost[i] = 0;
        boxes[i] = 0;
        for (int j = 0; j < (1<<13); j++) dp[i][j] = -1;
    }

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> cost[i];
        int q;
        cin >> q;
        int mask = 0;
        for (int j = 0; j < q; j++) {
            int x;
            cin >> x;
            x--;
            mask |= (1<<x);
        }
        boxes[i] = mask;
    }

    int res = recur(0, 0);
    if (res == 1e9) cout << "-1\n";
    else cout << res << '\n';
}
/*

 */