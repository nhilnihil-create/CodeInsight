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

    Int result = LLONG_MAX;
    Int root = floor(sqrt(n));
    for (Int i = 1; i <= root; ++i) {
        if (n % i == 0) {
            result = Min(result, i + n / i);
        }
    }
    cout << result - 2 << endl;
    return 0;
}
