#include <bits/stdc++.h>
using namespace std;
long long n, i = 0,  a = 10, b = 9, c = 8, mod = 1000000007;
int main() { cin >> n;
    for(; i < n - 1; i++) {
        a *= 10; a %= mod;
        b *= 9;  b %= mod;
        c *= 8;  c %= mod;
    }
    a += c; a %= mod;
  cout << (a - (2 * b) % mod + mod) % mod << endl;
}