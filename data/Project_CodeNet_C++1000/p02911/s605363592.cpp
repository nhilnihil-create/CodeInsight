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
    Int n, k, q;
    cin >> n >> k >> q;
    vector<Int> v(n, 0);
    for (Int i = 0; i < q; ++i) {
        Int a;
        cin >> a;
        a--;
        v[a]++;
    }
    for (Int i = 0; i < n; ++i) {
        if (q - v[i] < k) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
