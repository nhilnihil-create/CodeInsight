#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1000000007;

ll dp[100005];

int main() {
    ll N, M;
    cin >> N >> M;

    rep(i, N) dp[i + 1] = 0;
    dp[0] = 1;

    rep(i, M) {
        int a;
        cin >> a;
        dp[a] = -1;
    }

    rep(i, N) {
        if (dp[i + 1] == -1) continue;

        if (i == 0) {
            dp[1] = 1;
            continue;
        }

        if (dp[i] != -1) dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
        if (dp[i - 1] != -1) dp[i + 1] = (dp[i + 1] + dp[i - 1]) % mod;
    }

    cout << dp[N] << endl;
}