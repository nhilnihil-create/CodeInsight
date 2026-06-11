#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

// 二つの値の最小値を求める関数
Int Min(const Int a, const Int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}
// 二つの値の最大値を求める関数
Int Max(const Int a, const Int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    Int n, m, k;
    cin >> n >> m >> k;
    VI a(n + 2);
    VI b(m + 2);
    for (Int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[0] = 0;
    a[n + 1] = 1e09 + 7;
    for (Int i = 1; i <= n + 1; ++i) {
        a[i] += a[i - 1];
    }
    b[0] = 0;
    b[m + 1] = 1e09 + 7;
    for (Int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    for (Int i = 1; i <= m + 1; ++i) {
        b[i] += b[i - 1];
    }

    Int result = 0;
    Int i = 0;
    Int j = m + 1;
    while (1) {
        if (a[i] + b[j] > k) {
            --j;
            if (j == -1) {
                break;
            }
        } else {
            result = Max(result, i + j);
            ++i;
            if (i == n + 2) {
                break;
            }
        }
    }
    cout << result << endl;
    return 0;
}

