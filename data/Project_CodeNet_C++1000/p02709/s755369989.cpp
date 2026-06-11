#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long dp[2005][2005] = {};

int main() {
    
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a(n + 1);
    for (long long i = 1; i < n + 1; ++i) cin >> a[i].first, a[i].second = i;
    sort(a.begin() + 1, a.end(), greater<pair<long long, long long>>());
    for (long long i = 1; i < n + 1; ++i) {
        for (long long j = 0; j < i; ++j) {
            long long L = j;
            long long R = i - 1 - j;
            dp[L + 1][R] = max(
                dp[L + 1][R],
                dp[L][R] + abs(L + 1 - a[i].second) * a[i].first
            );
            R = j;
            L = i - 1 - j;
            dp[L][R + 1] = max(
                dp[L][R + 1],
                dp[L][R] + abs(n - R - a[i].second) * a[i].first
            );
        }
    }
    long long ans = 0;
    for (long long i = 1; i < n + 1; ++i) {
        ans = max(ans, dp[i][n - i]);
    }
    cout << ans << endl;

    return 0;
}