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

// 絶対値を求める
UInt Abs(const Int a) {
    return a > 0 ? a : -a;
}

void PermutationLoop(Int n, vector<Int>& p, vector<Int>& q) {
    vector<Int> v(n);  
    for (Int i = 0; i < n; ++i) {
        v[i] = i;
    }
    Int cnt = 0;
    Int pPermuPosi = -1;
    Int qPermuPosi = -1;
    do {
        bool isSameAsP = true;
        bool isSameAsQ = true;
        for (Int i = 0; i < n; ++i) {
            if (v[i] != p[i]) {
                isSameAsP = false;
            }
            if (v[i] != q[i]) {
                isSameAsQ = false;
            }
        }
        if (isSameAsP == true) {
            pPermuPosi = cnt;
        }
        if (isSameAsQ == true) {
            qPermuPosi = cnt;
        }
        ++cnt;
    } while (std::next_permutation(v.begin(), v.end()));
    cout << Abs(pPermuPosi - qPermuPosi) << endl;
    return;
}

int main(void) {
    // 入出力処理
    Int n; // ループする回数 n! を決めるパラメータ
    cin >> n;
    vector<Int> p(n);
    vector<Int> q(n);
    for (Int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    for (Int i = 0; i < n; ++i) {
        cin >> q[i];
        --q[i];
    }
    PermutationLoop(n, p, q);
    return 0;
}

