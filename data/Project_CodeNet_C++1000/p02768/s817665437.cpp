#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long my_pow(long long a, long long lv) {
    long long res = 1;
    long long p = a;
    while (lv) {
        if (lv & 1) res = res * p % MOD;
        p = p * p % MOD;
        lv >>= 1;
    }
    return res;
}

long long f(int l, int r) {
    long long res = 1;
    for (int i = l; i <= r; i++) {
        res = res * i % MOD;
    }
    return res;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b ;

    long long all = my_pow(2, n);
    all = (all + MOD - 1) % MOD;
    long long cntA = f(n - a + 1, n) * my_pow(f(1, a), MOD - 2) % MOD;
    long long cntB = f(n - b + 1, n) * my_pow(f(1, b), MOD - 2) % MOD;
    all = (all - cntA + MOD) % MOD;
    all = (all - cntB + MOD) % MOD;
    cout << all << endl;
}
