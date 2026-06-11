#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

bool cmp(pii &a, pii &b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, T;
    cin >> N >> T;
    vector<pii> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);

    vector<int> ma(N + 1);
    for (int i = N - 1; i >= 0; --i)
        ma[i] = max(ma[i + 1], v[i].second);

    int ans = ma[0];
    vector<vector<int>> dp(N + 1, vector<int>(T + 1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= T; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (j >= v[i].first)
                dp[i + 1][j] = max(dp[i][j - v[i].first] + v[i].second, dp[i + 1][j]);
        }
        ans = max(ans, dp[i + 1][T - 1] + ma[i + 1]);
    }
    ans = max(ans, dp[N][T]);

    cout << ans << endl;

    return 0;
}
