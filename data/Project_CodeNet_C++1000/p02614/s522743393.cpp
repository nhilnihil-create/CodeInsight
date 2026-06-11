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


Int CountBlack(vector<vector<char> >& table, char target) {
    Int height = table.size();
    Int width = table[0].size();
    Int cnt = 0;
    for (Int i = 0; i < height; ++i) {
        for (Int j = 0; j < width; ++j) {
            if (table[i][j] == target) {
                ++cnt;
            }
        }
    }
    return cnt;
}
bool Func(vector<vector<char> > table, Int hs, Int ws, Int k) {
    Int height = table.size();
    Int width = table[0].size();
    for (Int i = 0; i < height; ++i) {
        if (IsFlagUp(hs, i)) {
            for (Int j = 0; j < width; ++j) {
                table[i][j] = '.';
            }
        }
    }
    for (Int j = 0; j < width; ++j) {
        if (IsFlagUp(ws, j)) {
            for (Int i = 0; i < height; ++i) {
                table[i][j] = '.';
            }
        }
    }
    Int black = CountBlack(table, '#');
    //cout << black << endl;
    return (black == k);
}

int main(void) {
    Int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char> > c(h, vector<char>(w));
    for (Int i = 0; i < h; ++i) {
        for (Int j = 0; j < w; ++j) {
            cin >> c[i][j];
        }
    }

    Int result = 0;
    for (Int i = 0; i < pow(2, h); ++i) {
        for (Int j = 0; j < pow(2, w); ++j) {
            //cout << i << " " << j << " ";
            if (Func(c, i, j, k)) {
                ++result;
            }
        }
    }
    cout << result << endl;

    return 0;
}

