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
    VI b(n - 1);
    for (Int i = 0 ; i < n - 1; ++i) {
        cin >> b[i];
    }
    Int result = (b[0] + b[n - 2]);
    for (Int i = 1; i < n - 1; ++i) {
        result += Min(b[i - 1], b[i]);
    }
    cout << result << endl;
    return 0;
}
