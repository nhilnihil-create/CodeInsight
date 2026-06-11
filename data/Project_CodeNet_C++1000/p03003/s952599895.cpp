#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> S(N), T(M);
    for (int i = 0; i < N; i++)
        std::cin >> S[i];
    for (int i = 0; i < M; i++)
        std::cin >> T[i];

    std::vector<std::vector<int>> cs(N + 1, std::vector<int>(M + 1));
    cs[0][0] = 1;
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++) {
            if (i > 0)
                cs[i][j] = (cs[i][j] + cs[i - 1][j]) % MOD;
            if (j > 0)
                cs[i][j] = (cs[i][j] + cs[i][j - 1]) % MOD;
            if (i > 0 && j > 0) {
                cs[i][j] -= cs[i - 1][j - 1];
                cs[i][j] += cs[i][j] < 0 ? MOD : 0;
                if (S[i - 1] == T[j - 1])
                    cs[i][j] = (cs[i][j] + cs[i - 1][j - 1]) % MOD;
            }
        }

    std::cout << cs[N][M] << "\n";
}