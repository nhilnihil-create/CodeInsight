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
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<ll> dp(N);
    dp[0] = 1000;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = max(dp[j], dp[i]);
            dp[i] = max(dp[j] / A[j] * A[i] + dp[j] % A[j], dp[i]);
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}
