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
// 絶対値を求める
UInt Abs(const Int a) {
    return a > 0 ? a : -a;
}
int main(void) {
    Int n, k;
    cin >> n >> k;
    n = (n % k);
    n = Min(n, Abs(n - k));
    cout << n << endl;
    return 0;
}

