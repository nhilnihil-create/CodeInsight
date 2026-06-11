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

    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i] >> B[i];

    vector<int> dp(H + 3, 1e9);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= H; ++j) {
            dp[min(H, j + A[i])] = min(dp[j] + B[i], dp[min(H, j + A[i])]);
        }
    }

    cout << dp[H] << endl;

    return 0;
}
