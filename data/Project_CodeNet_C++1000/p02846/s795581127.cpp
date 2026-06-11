#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 1000000000000000007LL;
constexpr int inf = 1000000007;

// 切り上げ割り算
template <typename T>
T ceil_div(T a, T b) {
    return a > 0 && b > 0 ? (a + b - 1) / b : a / b;
}

int main() {
    ll t1, t2, a1, a2, b1, b2; cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    if (a1 > b1) {
        swap(a1, b1);
        swap(a2, b2);
    }
    ll s = a1 * t1 + a2 * t2;
    ll t = b1 * t1 + b2 * t2;
    if (s == t) cout << "infinity" << endl;
    else if (s < t) cout << 0 << endl;
    else {
        ll d1 = (b1 - a1) * t1;
        ll d = s - t;
        if (d1 % d == 0) cout << d1 / d * 2 << endl;
        else cout << d1 / d * 2 + 1 << endl;
    }
    return 0;
}