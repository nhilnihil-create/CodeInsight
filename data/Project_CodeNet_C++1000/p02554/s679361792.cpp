#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long powmod(long long x, long long y) {
        long long res = 1;
        for (long long i = 0; i < y; i++) {
            res = res * x % mod;
        }
        return res;
    }

int main() {
    int n;
    cin >> n;
    long long ans;
    ans = powmod(10, n) - powmod(9, n) - powmod(9, n) + powmod(8, n);
    ans %= mod;
    ans = (ans + mod)%mod;
    cout << ans << endl;
    return 0;
}