#include "bits/stdc++.h"

using namespace std;

const long long MOD = 1000000007;

long long factorial(long long n) {
    long long ret = 1;
    for (long long i = 2; i <= n; ++i) {
        ret *= i;
        ret %= MOD;
    }
    return ret;
}

long long modPow(long long n, long long p) {
    if (p == 0) {
        return 1;
    }
    else if (p % 2 == 0) {
        long long x = modPow(n, p / 2);
        return x * x % MOD;
    }
    else {
        long long x = modPow(n, p / 2);
        return ((x * x % MOD) * n) % MOD;
    }
}

void Main() {
    long long X, Y;
    cin >> X >> Y;

    if ((X + Y) % 3 != 0) {
        cout << 0 << endl;
        return;
    }
    long long generation = (X + Y) / 3;
    if (!(generation <= X && X <= 2 * generation && generation <= Y && Y <= 2 * generation)) {
        cout << 0 << endl;
        return;
    }

    // gen C (X - gen)
    // = gen! / ((X - gen)! * (2 * gen - X)!
    long long fgen = factorial(generation);
    long long fXmgen = factorial(X - generation);
    long long f2genmX = factorial(2 * generation - X);

    long long ans = fgen * modPow(fXmgen, MOD - 2);
    ans %= MOD;
    ans *= modPow(f2genmX, MOD - 2);
    ans %= MOD;
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
