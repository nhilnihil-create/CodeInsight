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
    vector<vector<long long>> dp(n - k + 1, vector<long long>(n + 1, INF));
    vector<vector<long long>> pd = dp;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        pd = dp;
        for (int j = 0; j < n - k; j++){
            for (int m = 0; m <= n; m++){
                if (dp[j][m] == INF) continue;
                pd[j + 1][id[h[i]]] = min(pd[j + 1][id[h[i]]], dp[j][m] + max(0, h[i] - res[m]));
            }
        }
        dp = pd;
    }
    long long ans = INF;
    for (int i = 0; i <= n; i++) ans = min(ans, dp[n - k][i]);
    printf("%lld\n", ans);
}
