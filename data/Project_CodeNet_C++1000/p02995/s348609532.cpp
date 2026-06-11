#include <iostream>
#include <numeric>
#include <cstdint>
using namespace std;

int main() {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;

    // CとDの最小公倍数
    auto lcmn = lcm(c, d);
    // A以上、B未満の間に存在するCの倍数の数 (B以下に存在する倍数の数 - A未満に存在する倍数の数)
    auto cn = b / c - (a - 1) / c;
    // A以上、B未満の間に存在するDの倍数の数
    auto dn = b / d - (a - 1) / d;
    // A以上。B未満の間に存在するCとDの最小公倍数の倍数の数
    auto cdn = b / lcmn - (a - 1) / lcmn;

    // 全体 - Cの倍数の数 - Dの倍数の数 + CとDの最小公倍数の倍数の数
    cout << (b - a + 1) - cn - dn + cdn << endl;
}

