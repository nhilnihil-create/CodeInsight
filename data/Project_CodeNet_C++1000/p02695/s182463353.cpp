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

// 二つの値の最大値を求める関数
Int Max(const Int a, const Int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

struct Data {
    Int a;
    Int b;
    Int c;
    Int d;
};

void dfs(vector<Int>& v, Int value, Int zero, Int one) {
    //cout << value << " " << zero << " " << one << endl;
    if (zero == 0 && one == 0) {
        v.push_back(value);
    }
    if (zero != 0) {
        dfs(v, value * 2, zero - 1, one);
    } 
    if (one != 0) {
        dfs(v, value * 2 + 1, zero, one - 1);
    }
    return;
}

int main(void) {
    Int n, m, q;
    cin >> n >> m >> q;
    vector<Data> data(q);
    for (Int i = 0; i < q; ++i) {
        cin >> data[i].a >> data[i].b >> data[i].c >> data[i].d;
        data[i].a--;
        data[i].b--;
    }
    vector<Int> v;
    dfs(v, 0, n, m - 1);

    Int score_max = 0;

    for (Int i = 0; i < (Int)v.size(); ++i) {
        Int rank_one = 0;
        vector<Int> a;
        for (Int j = 0; j < n + m - 1; ++j) {
            if (IsFlagDown(v[i], j)) {
                a.push_back(rank_one);
            } else {
                ++rank_one;
            }
        }
        Int inner_score = 0;
        for (Int j = 0; j < q; ++j) {
            if (a[data[j].b] - a[data[j].a] == data[j].c) {
                inner_score += data[j].d;
            }
        }
        score_max = Max(score_max, inner_score);
        /*
        for (Int j = 0; j < a.size(); ++j) {
            cout << a[j] << " ";
        }
        cout << endl << "SCORE = " << inner_score << endl;
        */
    }
    cout << score_max << endl;
    return 0;
}
