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
// 二つの値の最大値を求める関数
Int Max(const Int a, const Int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    Int w, h, x, y;
    cin >> w >> h >> x >> y;
    double half = (double)(w * h) / 2.0;
    if (w / 2 == x && w % 2 == 0 && h / 2 == y && h % 2 == 0) {
        cout << half << " " << 1 << endl;
    } else {
        cout << half << " " << 0 << endl;
    }
    return 0;
}
