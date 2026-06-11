#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

vector<long> divisors(long n) {
    vector<long> res;
    for (long x = 1; x * x <= n; x++) {
        if (n % x == 0) {
            res.push_back(x);
            if (x * x != n) res.push_back(n / x);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);

//  n = (k * x + 1) * k^y
//  y > 0: k - divisor of n
//  y = 0: n - 1 = kx
    long n;
    cin >> n;
    auto d1 = divisors(n);
    set<long> ans;
    for (long x : d1) {
        if (x == 1) continue;
        long nn = n;
        while (nn % x == 0) {
            nn /= x;
        }
        if (nn % x == 1) {
            ans.insert(x);
        }
    }
    auto d2 = divisors(n - 1);
    for (long x : d2) {
        if (x == 1) continue;
        ans.insert(x);
    }
    cout << ans.size();

    return 0;
}