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

    string S;
    cin >> S;
    int N = S.length();
    vector<vector<int>> dp(N + 1, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        dp[i + 1][0] = dp[i][1] + 1;
        if (i == 0 || S[i] != S[i - 1])
            dp[i + 1][0] = max(dp[i][0] + 1, dp[i + 1][0]);
        if (i > 0)
            dp[i + 1][1] = max(dp[i - 1][0] + 1, dp[i + 1][1]);
    }

    cout << max(dp[N][0], dp[N][1]) << endl;

    return 0;
}
