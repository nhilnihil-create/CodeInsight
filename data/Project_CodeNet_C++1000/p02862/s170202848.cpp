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
    long long A = 1, B = 1;
    for (int i = 0; i < r; i++) {
        A *= (n - i) % MOD;
        A %= MOD;
        B *= (r - i) % MOD;
        B %= MOD;
    }
    return A * modPow(B, MOD - 2) % MOD; 
}
 
int main() {
    long long X, Y; cin >> X >> Y;
    int n, m;
    if ((2 * X - Y) % 3 || (2 * Y - X) % 3) {
        cout << 0 << endl;
    } else {
        n = (2 * X - Y) / 3, m = (2 * Y - X) / 3;
        if (n < 0 || m < 0) {
            cout << 0 << endl;
        } else {
            cout << nCr(n + m, n) << endl;
        }
    }
}