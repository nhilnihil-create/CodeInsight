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
    Int x, y;
    cin >> x >> y;
    Int result = 0;
    if (x <= 3) {
        result += (4 - x) * 100000;
    }
    if (y <= 3) {
        result += (4 - y) * 100000;
    }
    if (x == 1 && y == 1) {
        result += 400000;
    }
    cout << result << endl;
    return 0;
}
