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

long long nCr(long long n, long long r) {
    if (r > n) return 0;
    return (fac[n] * modInverse(fac[r]) % MOD * modInverse(fac[n - r]) % MOD) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i < n; i += 2) sum -= a[i] * 2ll;
    vector<int> x(n);
    x[0] = sum;
    for (int i = 1; i < n; i++) {
        x[i] = a[i - 1] * 2 - x[i - 1];
    }
    for (int i = 0; i < n; i++) cout << x[i] << " ";

    return 0;
}