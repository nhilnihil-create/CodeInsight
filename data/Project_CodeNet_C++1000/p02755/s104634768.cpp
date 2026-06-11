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

// 二つの値の最大値を求める関数
Int Max(const Int a, const Int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}
// 分数の Ceil を求める関数
UInt Ceil(const UInt a, const UInt b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

int main(void) {
    Int a, b;
    cin >> a >> b;
    Int a_max, a_min, b_max, b_min;
    if (a % 2 == 0) {
        a_min = 25 * (a / 2);
        a_max = a_min + 12;
    } else {
        a_max = 25 * Ceil(a, 2) - 1;
        a_min = a_max - 11;
    }
    b_min = 10 * b;
    b_max = b_min + 9;

    Int result = 0;
    if (a_max < b_min || b_max < a_min) {
        result = -1;
    } else {
        result = Max(a_min, b_min);
    }
    cout << result << endl;
    return 0;
}

