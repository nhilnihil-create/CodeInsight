#include <iostream>
using namespace std;
const int MOD = 1000000007;

long long modPow(long long a, long long n) {
    if (n == 1) return a;
    if (n % 2) {
        return a * modPow(a, n - 1) % MOD;
    } else {
        return modPow(a * a % MOD, n / 2);
    }
}

long long nCr(long long n, long long r) {
    long long X = 1, Y = 1;
    for (int i = 0; i < r; i++) {
        X *= (n - i);
        X %= MOD;
        Y *= (r - i);
        Y %= MOD;
    }
    return X * modPow(Y, MOD - 2) % MOD; 
}

long long sub(long long &a, long long b) {
    a -= b;
    if (a < 0) return a += MOD;
    return a;  
}

int main() {
    long long n, a, b; cin >> n >> a >> b;
    long long ans = modPow(2, n) - 1;
    sub(ans, nCr(n, a));
    sub(ans, nCr(n, b));
    cout << ans << endl;
}