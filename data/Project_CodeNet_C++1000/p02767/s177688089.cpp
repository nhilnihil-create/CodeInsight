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
    Int n;
    cin >> n;
    vector<Int> x(n);
    for (Int i = 0; i < n; ++i) {
        Int temp;
        cin >> temp;
        x[i] = temp - 1;
    }
    const Int X_MAX = 100;
    Int min_sum = LLONG_MAX;
    for (Int i = 0; i < X_MAX; ++i) {
        Int sum = 0;
        for (Int j = 0; j < n; ++j) {
            sum += ((x[j] - i) * (x[j] - i));
        }
        min_sum = Min(min_sum, sum);
    }
    cout << min_sum << endl;
    return 0;
}

