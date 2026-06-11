#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 1e9 + 7;
int64_t fact[4013];

int64_t add_mod (int64_t a, int64_t b, int64_t m) {
    return (a + b) % m;
}

int64_t sub_mod (int64_t a, int64_t b, int64_t m) {
    return (a - b + m) % m;
}

int64_t mul_mod (int64_t a, int64_t b, int64_t m) {
    return (a * b) % m;
}

int64_t pow_mod (int64_t a, int64_t b, int64_t m) {
    int64_t res = 1, t = a;
    while (b) {
        if (b & 1)
            res = mul_mod(res, t, m);
        t = mul_mod(t, t, m);
        b >>= 1;
    }
    return res;
}

int64_t div_mod (int64_t a, int64_t b, int64_t m) {
    return mul_mod(a, pow_mod(b, m - 2, m), m);
}

int64_t ncr_mod (int64_t n, int64_t k, int64_t m) {
    return div_mod(fact[n], mul_mod(fact[n - k], fact[k], m), m);
}

void precalc (int64_t m) {
    fact[0] = 1;
    for (int64_t i = 1; i < 4013; ++i)
        fact[i] = mul_mod(fact[i - 1], i, m);
}

signed main () {
    precalc(mod);
    
    int64_t n, k;
    cin >> n >> k;
    for (int64_t moves = 1; moves <= k; ++moves) {
        if (moves <= n + 1 - k)
            cout << mul_mod(ncr_mod(k - 1, moves - 1, mod), ncr_mod(n + 1 - k, moves, mod), mod) << '\n';
        else
            cout << "0\n";
    }
}
