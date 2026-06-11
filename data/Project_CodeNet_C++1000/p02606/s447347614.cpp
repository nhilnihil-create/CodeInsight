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
    Int l, r, d;
    cin >> l >> r >> d;
    if (l % d == 0) {
        cout << r / d - l / d + 1 << endl;
    } else {
        cout << r / d - l / d << endl;
    }
    return 0;
}
