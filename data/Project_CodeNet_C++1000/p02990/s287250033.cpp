#include <iostream>
#include <vector>

const long long MOD = 1000000007;

int main() {
    int N, K;
    std::cin >> N >> K;

    auto pow = [](long long a, int n) {
        long long res = 1;
        for (; n; n >>= 1) {
            if (n & 1)
                res = res * a % MOD;
            a = a * a % MOD;
        }
        return res;
    };

    std::vector<long long> table(N + 1), inv_table(N + 1);
    table[0] = 1;
    for (int i = 1; i <= N; i++)
        table[i] = table[i - 1] * i % MOD;
    inv_table[N] = pow(table[N], MOD - 2);
    for (int i = N; i > 0; i--)
        inv_table[i - 1] = inv_table[i] * i % MOD;

    auto comb = [&table, &inv_table](int n, int r) {
        if (n < r)
            return 0LL;
        long long tmp = inv_table[n - r] * inv_table[r] % MOD;
        return table[n] * tmp % MOD;
    };

    for (int i = 1; i <= K; i++) {
        int ans = comb(N - K + 1, i) * comb(K - 1, i - 1) % MOD;
        std::cout << ans << "\n";
    }
}