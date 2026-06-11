#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

const long MOD = 1000000007;

long power(long a, long b) {
    long res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<long> cnt(k + 1);
    for (int d = 1; d <= k; d++) {
        cnt[d] = power(k / d, n);
    }
    for (int d = k; d >= 1; d--) {
        for (int x = 2; d * x <= k; x++) {
            cnt[d] -= cnt[d * x];
            if (cnt[d] < 0) cnt[d] += MOD;
        }
    }
    long res = 0;
    for (int d = 1; d <= k; d++) {
        res += d * cnt[d];
        res %= MOD;
    }
    cout << res << "\n";

    return 0;
}