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

// 分数の Ceil を求める関数
UInt Ceil(const UInt a, const UInt b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

int main(void) {
    Int n;
    cin >> n;
    cout << Ceil(n, 2) - 1 << endl;
    return 0;
}
