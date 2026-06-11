#include <bits/stdc++.h>
#define INF 0x7ffffffffff
using namespace std;
const int N = 2005;
long long dp[N][N] = {};
pair<long long, int> arr[N];
int n;
inline bool cmp(const pair<long long , int> &a, const pair<long long , int> &b) {
    return a.first > b.first;
}
long long DP(int l, int r) {
    if (l < 0 || r > n + 1) return -INF;
    if (~dp[l][r]) return dp[l][r];
    long long t = l + n - r + 1;
    long long val = arr[t].first, idx = arr[t].second;
    return dp[l][r] = max(DP(l - 1, r) + val * abs(idx - l), DP(l, r + 1) + val * abs(idx - r));
}
int main() {
    cin >> n;
    fill(dp[0], dp[0] + N * N, -1);
    dp[0][n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    long long ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, DP(i, i + 1));
    cout << ans << '\n';
    return 0;
}