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
    string S;
    cin >> N >> S;

    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (S[i] == S[j]) {
                int tmp = dp[i][j] + 1;
                if (dp[i + 1][j + 1] < tmp && tmp <= j - i) {
                    dp[i + 1][j + 1] = tmp;
                    ans = max(ans, tmp);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
