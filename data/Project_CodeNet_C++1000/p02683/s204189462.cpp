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

// ビット演算
namespace Bits {
    // 整数 x を左に i ビットシフトした値を返す
    static Int LeftBitShift(Int x, Int i);
    // 整数 x を右に i ビットシフトした値を返す
    static Int RightBitShift(Int x, Int i);
    // 整数x の 下から i 桁目が1かどうかを返す
    static bool IsFlagUp(Int x, Int i);
    // 整数x の 下から i 桁目が0かどうかを返す
    static bool IsFlagDown(Int x, Int i);

    // 整数 x を左に i ビットシフトした値を返す
    Int LeftBitShift(Int x, Int i) {
        return (x << i);
    }
    // 整数 x を右に i ビットシフトした値を返す
    Int RightBitShift(Int x, Int i) {
        return (x >> i);
    }
    // 整数x の 下から i 桁目が1かどうかを返す
    bool IsFlagUp(Int x, Int i) {
        return ((x & (1 << i)) != 0);
    }
    // 整数x の 下から i 桁目が0かどうかを返す
    bool IsFlagDown(Int x, Int i) {
        return ((x & (1 << i)) == 0);
    }
}
using namespace Bits;

// 二つの値の最小値を求める関数
Int Min(const Int a, const Int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

struct Book {
    Int cost;
    vector<Int> a;
};

int main(void) {
    Int n, m, x;
    cin >> n >> m >> x;
    vector<Book> list(n);
    for (Int i = 0; i < n; ++i) {
        cin >> list[i].cost;
        list[i].a.resize(m);
        for (Int j = 0; j < m; ++j) {
            cin >> list[i].a[j];
        }
    }
    /*
    for (Int i = 0; i < n; ++i) {
        cout << list[i].cost << endl;
        for (Int j = 0; j < m; ++j) {
            cout << list[i].a[j] << " ";
        }
        cout << endl;
    }
    */
    Int loop = pow(2, n);
    Int min_cost = LLONG_MAX;;
    for (Int i = 0; i < loop; ++i) {
        Int now_cost = 0;
        vector<Int> level(m, 0);
        for (Int j = 0; j < n; ++j) {
            if (IsFlagUp(i, j)) {
                for (Int k = 0; k < m; ++k) {
                    level[k] += list[j].a[k];
                }
                now_cost += list[j].cost;
            }
        }
        bool can_understand = true;
        for (Int j = 0; j < m; ++j) {
            if (level[j] < x) {
                can_understand = false;
            }
        }
        if (can_understand) {
            min_cost = Min(min_cost, now_cost);
        }
    }

    if (min_cost == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
    }
    return 0;
}

