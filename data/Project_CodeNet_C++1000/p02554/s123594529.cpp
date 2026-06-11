#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

ll modexp(ll b, ll e) {
    if (e == 0) return 1;
    else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

ll FMOD(ll x) {
    return (x % MOD + MOD) % MOD;
}

int main() {
    int n; scanf("%d", &n);
    ll comple = 2 * modexp(9, n) - modexp(8, n);
    printf("%lld\n", FMOD(modexp(10, n) - comple));
    return 0;
}
