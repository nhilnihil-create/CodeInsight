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

    int N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;

    vector<vector<int>> dp(N + K, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        dp[i + K][0] = max(dp[i][1], dp[i][2]);
        dp[i + K][1] = max(dp[i][2], dp[i][0]);
        dp[i + K][2] = max(dp[i][0], dp[i][1]);
        if (T[i] == 's')
            dp[i + K][0] += R;
        if (T[i] == 'p')
            dp[i + K][1] += S;
        if (T[i] == 'r')
            dp[i + K][2] += P;
    }

    int ans = 0;
    for (int i = N; i < N + K; ++i)
        ans += max(dp[i][0], max(dp[i][1], dp[i][2]));
    cout << ans << endl;

    return 0;
}
