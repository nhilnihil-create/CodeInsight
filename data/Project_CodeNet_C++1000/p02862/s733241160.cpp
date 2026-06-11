#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MX = 1e6 + 10;;
unsigned long long fac[1000010];

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


int main() {
    int x, y;
    cin >> x >> y;
    if ((x + y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int n = (x + y) / 3;
    int u = x - n;
    int     v = y - n;
    if (u < 0 || v < 0) {
        cout << 0 << endl;
        return 0;
    }
    fac[0] = 1; fac[1] = 1;
    for (int i = 1; i < MX; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    
    cout << (fac[n] * modInverse(fac[u]) % MOD * modInverse(fac[n-u]) % MOD) % MOD;
    return 0;
}