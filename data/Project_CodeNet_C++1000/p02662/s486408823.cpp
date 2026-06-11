#include <bits/stdc++.h>

int main() {
    int N, S;
    std::cin >> N >> S;

    int A[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    const int64_t MOD = 998244353;
  
    // dp[i][j]: 最初の i 個について考えたとき、総和が j になる部分集合を含む集合の個数
    // 1. A[i] を選ばない場合、部分集合自体は変化しないが、それを含む集合の個数は 2 倍になるので、dp[i+1][j] += dp[i][j] * 2
    // 2. A[i] が選べるなら、dp[i+1][j] += dp[i][j-A[i]]
    std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(S + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= S; ++j) {
            dp[i+1][j] += dp[i][j] * 2 % MOD;
            if (j - A[i] >= 0) {
                dp[i+1][j] += dp[i][j-A[i]];
                dp[i+1][j] %= MOD;
            }
        }
    }

    std::cout << dp[N][S] << std::endl;

    return 0;
}
