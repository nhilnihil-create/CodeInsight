#include <algorithm>
#include <iostream>

long long gcd(long long a, long long b)
{
    long long M = std::max(a, b);
    long long m = std::min(a, b);
    if (M % m == 0)
        return m;
    return gcd(m, M % m);
}

int main()
{
    bool sieve[1000002];
    long long a, b;
    std::cin >> a >> b;

    long long g = gcd(a, b);
    long long p = 2;
    bool end = false;
    long long ans = 1;
    while (p < 1000001 && !end && g != 1) {

        if (g % p == 0)
            ans++;
        while (g % p == 0) {
            g /= p;
        }
        for (int i = p * 2; i < 1000002; i += p) {
            sieve[i] = true;
        }
        for (int i = p + 1; i < 1000002; i += 1) {
            if (!sieve[i]) {
                p = i;
                break;
            }
            if (i == 1000001)
                end = true;
        }
    }
    if (g != 1)
        ans++;
    std::cout << ans << "\n";
    return 0;
}
