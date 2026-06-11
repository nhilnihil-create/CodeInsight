#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {

    size_t N;
    cin >> N;
    vector<pair<long long, long long>> a(N + 1);
    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));
    for (size_t i = 1; i <= N; ++i) {
        cin >> a[i].first;
        a[i].second = (long long)i;
    }
    sort(a.begin() + 1, a.end(), greater<pair<long long, long long>>());
    for (size_t i = 1; i <= N; ++i) {
        for (size_t j = 0; j < i; ++j) {
            auto l = j;
            auto r = i - 1 - j;
            dp[l + 1][r] = max(dp[l + 1][r], dp[l][r] + a[i].first * abs((long long)l + 1 - a[i].second));
            dp[r][l + 1] = max(dp[r][l + 1], dp[r][l] + a[i].first * abs((long long)N - (long long)l - a[i].second));
        }
    }
    long long res = 0;
    for (size_t i = 1; i <= N; ++i) {
        res = max(res, dp[i][N - i]);
    }
    cout << res;
    return 0;
}