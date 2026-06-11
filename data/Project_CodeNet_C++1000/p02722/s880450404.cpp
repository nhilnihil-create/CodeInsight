#include <bits/stdc++.h>

// return the divisor of n
std::vector<int64_t> divisor(int64_t n) noexcept {
    std::vector<int64_t> ret;
    for (int64_t i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i != 1) {
                ret.push_back(i);
            }

            if (i != n / i) {
                ret.push_back(n / i);
            }
        }
    }

    return ret;
}

int main() {
    int64_t N;
    std::cin >> N;

    int64_t ans = 0;
    const std::vector<int64_t> n1 = divisor(N - 1);
    ans += n1.size();

    const std::vector<int64_t> n = divisor(N);
    for (int64_t v : n) { 
        int64_t buf = N; 
        while (buf % v == 0) {
            buf /= v;
        }

        if (buf % v == 1) {
            ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
