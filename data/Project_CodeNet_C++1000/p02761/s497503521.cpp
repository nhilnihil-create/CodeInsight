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

int main(void) {
    Int n, m;
    cin >> n >> m;

    // 指定された各桁の値を格納する配列
    vector<Int> v(n, -1);

    // 条件を満たす整数が存在するかどうかの真偽値
    bool result = true;
    for (Int i = 0; i < m; ++i) {
        Int s, c;
        cin >> s >> c;
        --s;
        if (v[s] == -1) { // まだ指定されていない場合
            v[s] = c;
        } else if (v[s] != c) { // 既に異なる値を指定していた場合
            result = false;
        }
    }

    // 配列内の値を題意に合うように変更する
    // 一番上の桁を処理
    if (n == 1) {
        if (v[0] == -1) {
            v[0] = 0;
        }
    } else {
        if (v[0] == 0) {
            result = false;
        } else if (v[0] == -1) {
            v[0] = 1;
        }
    }
    // 上から二番目以降の桁を処理
    for (Int i = 1; i < n; ++i) {
        if (v[i] == -1) {
            v[i] = 0;
        }
    }

    Int answer = 0;
    if (!result) {
        answer = -1;
    } else {
        // 配列内の要素を整数に整形する
        for (Int i = 0; i < n; ++i) {
            answer *= 10;
            answer += v[i];
        }
    }
    cout << answer << endl;
    return 0;
}

