#include <iostream>
#include <vector>
#include <string>

int main() {
    const int MOD = 1000000007;

    std::string S;
    std::cin >> S;

    int N = S.size();

    std::vector<
        std::vector<int>
    > dp(N + 1, std::vector<int>(13));
    
    dp[0][0] = 1;

    int p = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 13; j++) {
            if (S[N - 1 - i] == '?') {
                for (int k = 0; k < 10; k++) {
                    int& x = dp[i + 1][(j + p * k) % 13];
                    x += dp[i][j];
                    x %= MOD;
                }
            }
            else {
                int k = S[N - 1 - i] - '0';
                int& x = dp[i + 1][(j + p * k) % 13];
                x += dp[i][j];
                x %= MOD;
            }
        }

        p = p * 10 % 13;
    }

    std::cout << dp[N][5] << "\n";
}