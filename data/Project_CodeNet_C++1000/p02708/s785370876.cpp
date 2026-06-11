#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main(void) {
    long long N, K;
    std::cin >> N >> K;

    long long ans = 0;
    for (long long i = K; i <= N + 1; i++) {
        ans = (ans +
               (N * (N + 1) / 2 - (N - i) * (N - i + 1) / 2 - i * (i - 1) / 2) +
               1) %
              MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
