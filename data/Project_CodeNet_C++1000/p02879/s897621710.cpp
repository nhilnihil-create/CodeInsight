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

Int Max(const Int a, const Int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    Int a, b;
    cin >> a >> b;
    if (a <= 9 && b <= 9) {
        cout << a * b << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
