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
    Int array[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    Int k;
    cin >> k;
    --k;
    cout << array[k] << endl;
    return 0;
}
