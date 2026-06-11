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

// 分数を小数に変換する関数
double Fraction(Int numerator, Int denominator) {
    return (double)((double)(numerator) / (double)(denominator));
}

int main(void) {
    Int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << 0.5 << endl;
    } else {
        cout << Fraction(n / 2 + 1, n) << endl;
    }
}
