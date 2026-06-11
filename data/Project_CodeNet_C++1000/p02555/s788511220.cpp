#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7, N = 2005;
int n, dp[N], s;

int solve(int sum) {
    if (sum > s) return 0;
    if (sum == s) return 1;
    int res = 0, &ans = dp[sum];
    if (~ans) return ans;
    for (int i = 3; i <= s; i++) {
        res += (solve(sum + i));
        res %= mod;
    }
    return ans = res;
}
int32_t main() {
    for (int i = 0; i < N; i++) {
        dp[i] = -1;
    }
    cin >> s;
    cout << solve(0);
}
