#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

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

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> zerobit(61);
    vector<int> onebit(61);
    for (int i = 0; i < n; i++) {
        for (long long bit = 0; bit <= 60; bit++) {
            if (a[i] & (1ll << bit)) onebit[bit]++;
            else zerobit[bit]++;
        }
    }
    long long ans = 0;
    for (long long bit = 0; bit <= 60; bit++) {
        ans = ((ans % MOD) + (((zerobit[bit] % MOD * onebit[bit] % MOD) % MOD) * ((1ll << bit) % MOD)) % MOD) % MOD;
    }
    cout << ans;
    return 0;
}