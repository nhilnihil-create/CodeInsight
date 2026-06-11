#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
constexpr ll M = 1e9 + 7;
inline ll sum_1(const ll n) { return ((n * (n + 1)) / 2) % M; }
inline ll sum_2(const ll n) { return ((n * (n + 1) * (2 * n + 1)) / 6) % M; }
inline ll sum_3(const ll n) { return (((n * (n + 1)) / 2) % M * ((n * (n + 1)) / 2) % M) % M; }
inline ll sum_1(const ll i, const ll j) { return (sum_1(j) - sum_1(i - 1) + M) % M; }
inline ll sum_2(const ll i, const ll j) { return (sum_2(j) - sum_2(i - 1) + M) % M; }
inline ll sum_3(const ll i, const ll j) { return (sum_3(j) - sum_3(i - 1) + M) % M; }

void solve() {
    int n;
    cin >> n;

    /**
     * dp[l][r] = max(dp[l-1][r] + Ai * |idx-l|,
     *                  dp[l][r-1] + Ai * |n-idx|)
     */
    vector<pair<ll,ll>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first;
        A[i].second = i; 
    }
    sort(A.begin(), A.end(), greater<pair<ll,ll>>());

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            int curr_ele = i+j-1;
            if (curr_ele < 0 || curr_ele >= n) {
                continue;
            }
            if (i > 0) {
                dp[i][j] = max(
                    dp[i][j], 
                    dp[i-1][j] + A[curr_ele].first * abs(A[curr_ele].second - i + 1)
                );
            }
            if (j > 0) {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i][j-1] + A[curr_ele].first * abs(n - j - A[curr_ele].second)
                );
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp[i][n-i]);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif

    solve();

    return 0;
}