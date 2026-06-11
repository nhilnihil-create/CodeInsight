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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pii> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end(), greater<pii>());
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i + 1][j] = max(dp[i][j] + (ll)A[i].first * abs(i - j - A[i].second), dp[i + 1][j]);
            dp[i + 1][j + 1] = dp[i][j] + (ll)A[i].first * abs(N - j - 1 - A[i].second);
        }
    }

    ll ans = 0;
    for (int i = 0; i <= N; ++i)
        ans = max(ans, dp[N][i]);
    cout << ans << endl;
    return 0;
}
