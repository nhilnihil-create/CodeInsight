#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

LL qpow(int a, int b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1; 
    }
    return res;
}

int main() {
    LL n;
    cin >> n;
    if (n == 1) cout << 0 << '\n';
    else cout << (qpow(10, n) - qpow(9, n) * 2 % mod + qpow(8, n) + mod) % mod << '\n';
    return 0; 
}