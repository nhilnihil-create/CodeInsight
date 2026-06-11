#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
const int MAX = 1'000'000;
const int MOD = 1'000'000'000 + 7;
long long int fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long int COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int f(int x, int y) {
    const int aTimesThree = -1 * x + 2 * y;
    const int bTimesThree = 2 * x - y;

    if (aTimesThree % 3 != 0) return 0;
    if (bTimesThree % 3 != 0) return 0;

    const int a = aTimesThree / 3;
    const int b = bTimesThree / 3;

    return COM(a + b, a);
}

int main() {

    COMinit();

    int X, Y; // the target coordinate
    std::cin >> X >> Y;

    std::cout << f(X, Y) << std::endl;

    return 0;

}
