#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MX = 1e10 + 10;;
unsigned long long fac[200001];

#include <math.h>
#define PI 3.14159265358979323846264338327950L

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}
long long digits(long long m) {
    long long cnt = 0;
    while (m) {
        cnt++;
        m /= 10;
    }
    return cnt;
}

unsigned long long power(unsigned long long x, unsigned long long y){
    unsigned long long res = 1;
    x = x % MOD;

    while (y > 0) {
        // If y is odd, multiply x with result 
        if (y & 1)
            res = (res * x) % MOD;

        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % MOD;
    }
    return res;
}
unsigned long long modInverse(unsigned long long n) {
    return power(n, MOD - 2);
}

long long mxN = 2e5+1;
long long nCr(long long n, long long r) {
    if (r > n) return 0;
    return (fac[n] * modInverse(fac[r]) % MOD * modInverse(fac[n - r]) % MOD) % MOD;
}
int main() {
    memset(fac, 0, sizeof(fac));
    long long n, k;
    cin >> n >> k;
    fac[0] = 1;
    for (int i = 1; i < mxN; i++)
        fac[i] = (fac[i - 1] * i) % MOD;

    long long r = n - k;
    long long b = k;

    for (long long i = 1; i < k + 1; i++) {
        long long x = nCr(r + 1ll, i);
        long long y = nCr(b - 1ll, i - 1ll);
        long long ans = x * y; ans %= MOD;
        cout << ans << "\n";
    }
    return 0;
}