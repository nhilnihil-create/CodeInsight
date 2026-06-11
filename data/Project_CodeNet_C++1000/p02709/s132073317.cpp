#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 10, mod = 1e9 + 7;

pair<int, int> arr[N];
long long dp[N][N];
int n;

long long solve(int i, int l) {
    if(!arr[i].first) return 0;
    if(dp[i][l] != -1) return dp[i][l];
    int r = n - (i - l);
    long long ret = solve(i + 1, l + 1) + 1ll * arr[i].first * abs(arr[i].second - l);
    ret = max(ret, solve(i + 1, l) + 1ll * arr[i].first * abs(arr[i].second - r));
    return dp[i][l] = ret;
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
    //scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i].first);
            arr[i].second = i + 1;
        }
        sort(arr, arr + n, greater<pair<int, int>>());
        //for(int i = 1; i <= n; i++) cout << arr[i].first << ' ' << arr[i].second << '\n';
        //memset(dp, -1, sizeof(dp));
        //cout << solve(1, 1);
        for(int i = 0; i < n; i++) {
            for(int l = 1; l < i + 2; l++) {
                int r = n - (i - l + 1);
                //cout << i << ' ' << l << ' ' << r << '\n';
                dp[i + 1][l + 1] = max(dp[i + 1][l + 1], dp[i][l] + 1ll * abs(arr[i].second - l) * arr[i].first);
                dp[i + 1][l] = max(dp[i + 1][l], dp[i][l] + 1ll * abs(arr[i].second - r) * arr[i].first);
            }
        }
        //cout << dp[1][2] << ' ' << dp[2][2] << ' ' << dp[3][3] << ' ' << dp[4][4] << '\n';
        long long ans = 0;
        for(int l = 1; l <= n + 1; l++) ans = max(ans, dp[n][l]);
        printf("%lld\n", ans);
    }    
    return 0;
}