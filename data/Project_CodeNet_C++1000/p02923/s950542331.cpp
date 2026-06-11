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

int main(void) {
    Int n;
    cin >> n;
    vector<Int> h(n);
    for (Int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector<Int> CanMove(n);
    for (Int i = 0; i < n - 1; ++i) {
        if (h[i] >= h[i + 1]) {
            CanMove[i] = 1;
        } else {
            CanMove[i] = 0;
        }
    }
    CanMove[n - 1] = 0;
    Int maxMove = 0;
    Int tempMove = 0;
    for (Int i = 0; i < n - 1; ++i) {
        if (CanMove[i] == 1) {
            tempMove++;
            maxMove = Max(maxMove, tempMove);
        } else {
            tempMove = 0;
        }
    }
    cout << maxMove << endl;
    return 0;
}
