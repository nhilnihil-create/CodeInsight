// header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;
using llong = long long;

// library section
// ===

llong n;
llong ans;

bool check(llong k) {
    if (k == 1) return false;

    llong a = n;

    while (a % k == 0) a /= k;
    
    return a % k == 1;
}

int main() {
    cin >> n;

    llong m = n - 1;
    for (llong i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            if (m / i == i) {
                if (check(i)) ans++;
            }
            else {
                if (check(i)) ans++;
                if (check(m / i)) ans++;
            }
        }
    }

    for (llong i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                if (check(i)) ans++;
            }
            else {
                if (check(i)) ans++;
                if (check(n / i)) ans++;
            }
        }
    }

    if (check(m)) ans++;
    if (check(n)) ans++;

    cout << ans << endl;

    return 0;
};

