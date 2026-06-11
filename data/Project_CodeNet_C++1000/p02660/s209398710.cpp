#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

using ll = long long;
using lli = long long int;

std::vector<std::pair<lli, lli>> prime_factor(lli n) {
    lli ex;
    std::vector<std::pair<lli, lli>> vec;
    for (lli i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ex = 0;
            while (n % i == 0) {
                ex++;
                n /= i;
            }
            vec.push_back(std::make_pair(i, ex));
        }
    }
    if (n != 1) {
        vec.push_back(std::make_pair(n, 1));
    }
    return vec;
}


lli n, ans;
int main() {
    std::cin >> n;
    lli c = 0;
    auto primes = prime_factor(n);
    for (lli i = 0; i < primes.size(); i++) {
        lli f = primes[i].first;
        lli s = primes[i].second;
        //std::cout << "f=" << primes[i].first << "," << "s=" << primes[i].second << std::endl;
        if (n % f == 0) {
            lli t = f;
            while (n % f == 0) {
                n /= f;
                s--;
                c++;
                f *= t;
                if (s == 0) {
                    break;
                }
            }
        }

    }
    std::cout << c << std::endl;

}
