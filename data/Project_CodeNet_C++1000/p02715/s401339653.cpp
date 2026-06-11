#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long fpow(long long a, long long b) { long long ret = 1; while (b) { if (b & 1) ret = ret * a %mod; a = a * a % mod; b >>= 1; } return ret; }

int main() {
    long long n, k; cin >> n >> k;
    long long gcd[k+1] = {};
    for (int i = 1; i <= k; i++)
        gcd[i] = fpow(k / i, n);
    for (int i = k / 2; i >= 1; i--)
        for (int j = i + i; j <= k; j += i)
            gcd[i] -= gcd[j];
    for (int i = 1; i <= k; i++)
        gcd[i] = i * gcd[i] % mod;
    cout << accumulate(gcd + 1, gcd + 1 + k, 0LL) % mod;
}