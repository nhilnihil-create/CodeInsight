#include "bits/stdc++.h"

using namespace std;

const long long MOD = 1000000007;

void Main() {
    long long m, n;
    cin >> m >> n;

    bitset<35> bit(n);
    long long pow = m;
    long long ans = 1;
    for (int i = 0; i < 35; ++i) {
        if (bit[i]) {
            ans *= pow;
            ans %= MOD;
        }
        pow *= pow;
        pow %= MOD;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

