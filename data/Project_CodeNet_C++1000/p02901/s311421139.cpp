#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pdd = pair<double, double>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> dp(M + 1, vector<int>(1 << N, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < M; ++i) {
        int a, b, bit = 0;
        cin >> a >> b;
        for (int j = 0; j < b; ++j) {
            int c;
            cin >> c;
            bit |= 1 << (c - 1);
        }
        for (int j = 0; j < 1 << N; ++j) {
            dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
            dp[i + 1][j | bit] = min(dp[i][j] + a, dp[i + 1][j | bit]);
        }
    }

    cout << (dp[M][(1 << N) - 1] < 1e9 ? dp[M][(1 << N) - 1] : -1) << endl;

    return 0;
}
