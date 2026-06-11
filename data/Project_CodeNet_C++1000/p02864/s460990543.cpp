#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

long long dp[310][310][310] = {};

void solve(long long N, long long K, std::vector<long long> H) {


    for (int i = 0; i < 310; i++) {
        for (int j = 0; j < 310; j++) {
            for (int k = 0; k < 310; k++) {
                dp[i][j][k] = 1e18;
            }

        }
    }



    H.insert(H.begin(), 0);

    dp[1][0][0] = 0;
    for (int i = 1; i < H.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                // 使う
                dp[i + 1][i][k + 1] = min(dp[i + 1][i][k + 1], dp[i][j][k] + max(0ll, H[i] - H[j]));
                //使わない
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);

            }
        }
    }
    long long ans = 1e18;
    for (int i = N - K; i <= N; i++) {
        for (int j = 0; j < H.size(); j++) {
            ans = min(ans, dp[H.size()][j][i]);
        }
    }
    cout << ans << endl;

}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &H[i]);
    }
    solve(N, K, std::move(H));
    return 0;
}
