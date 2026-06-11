#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

const llong mod = (llong)(1e9) + 7;

llong mod_pow(llong n, llong m) {
    llong ret = 1;

    while (m) {
        if (m & 1) {
            ret *= n;
            ret %= mod;
        }

        m >>= 1;
        n *= n;
        n %= mod;
    }

    return ret;
}

llong n, k;
llong sum;
llong cnt[100005];

int main() {
    cin >> n >> k;

    for (llong i = k; i >= 1; i--) {
        sum += i * ((mod_pow(k / i, n) - cnt[i] + mod) % mod) % mod;
        sum %= mod;
        
        llong add = mod_pow(k / i, n) - cnt[i];

        for (llong j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (i / j == j) {
                    cnt[j] += add;
                    cnt[j] %= mod;
                }
                else {
                    cnt[j] += add;
                    cnt[j] %= mod;
                    cnt[i / j] += add;
                    cnt[i / j] %= mod;
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}
