#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    long long N;
    std::cin >> N;

    std::vector<long> primes;
    // 8 -> [(2, 3)]
    // 24 -> [(2, 3), (3, 1)] -> (_^1 * _^2) * (3^1)
    for (long long i=2; i*i<=N; i++) {
        if (i > N) break;
        long long count = 0;
        while (N%i == 0) {
            N /= i;
            count++;
        }
        if (count > 0) {
            primes.push_back(count);
        }
    }
    if (N != 1) {
        primes.push_back(1);
    }
    long long result = 0;
    for (auto const& e : primes) {
        // l*(l+1)/2 <= e < (l+1)*(l+2)/2 となるようなl
        long long l = 1;
        while (true) {
            auto flag = l*(l+1) <= 2*e && 2*e < (l+1)*(l+2);
            if (flag) {
                break;
            }
            l++;
        }
        result += l;
    }
    std::cout << result << std::endl;
}