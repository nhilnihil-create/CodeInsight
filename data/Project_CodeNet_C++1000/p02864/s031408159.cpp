#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    if (scanf("%d %d", &n, &k) < 2) exit(1);
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &h[i]) < 1) exit(1);
    }
    vector<int> a = h;
    sort(a.begin(), a.end());
    //座圧 -> id 復元 -> res
    map<int, int> id;
    map<int, int> res;
    int now = 1;
    for (int i = 0; i < n; i++){
        if (id[a[i]] == 0) {
            id[a[i]] = now;
            res[now] = a[i];
            now++;
        }
    }
    long long INF = ((long long)1 << 40);
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n - k + 1, vector<long long>(n + 1, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= n - k; j++){
            for (int m = 0; m <= n; m++){
                if (dp[i][j][m] == INF) continue;
                dp[i + 1][j][m] = min(dp[i + 1][j][m], dp[i][j][m]);
                if (j == n - k) continue;
                dp[i + 1][j + 1][id[h[i]]] = min(dp[i + 1][j + 1][id[h[i]]], dp[i][j][m] + max(0, h[i] - res[m]));
            }
        }
    }
    long long ans = INF;
    for (int i = 0; i <= n; i++) ans = min(ans, dp[n][n - k][i]);
    printf("%lld\n", ans);
}
