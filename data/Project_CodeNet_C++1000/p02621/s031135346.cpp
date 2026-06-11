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
    Int a;
    cin >> a;
    Int result = a;
    for (Int i = 0; i < 2; ++i) {
        result += 1;
        result *= a;
    }
    cout << result << endl;
    return 0;
}
