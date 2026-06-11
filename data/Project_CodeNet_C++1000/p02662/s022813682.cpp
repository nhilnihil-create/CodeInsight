#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 998244353;

// dp[i][j] => starting from i items already considered and sum of such items(taken in set both U and T) is j

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for(auto& x : arr) cin >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(s + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int sum = 0; sum <= s; sum++) {
            dp[i + 1][sum] += 2 * dp[i][sum]; // no of sets of length (i + 1) in T is doubled since all sets of dp[i][sum] are inclued in dp[i + 1][sum] and same sets with a[i] included in T
            dp[i + 1][sum] %= MOD;
            if(sum + arr[i] <= s) {
                dp[i + 1][sum + arr[i]] += dp[i][sum];
                dp[i + 1][sum + arr[i]] %= MOD;
            }
        }
    }
    cout << dp[n][s];
    return 0;
}
