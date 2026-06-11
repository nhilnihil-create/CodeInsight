#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
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

int main(void) {
    const Int MOD = 2019;
    Int l, r;
    cin >> l >> r;
    r = Min(r, l + MOD);
    Int result = MOD;
    for (Int i = l; i <= r; ++i) {
        for (Int j = i + 1; j <= r; ++j) {
            result = Min(result, (i * j) % MOD);
        }
    }
    cout << result << endl;
    return 0;
}
