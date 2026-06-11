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
    Int a[5];
    for (Int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    for (Int i = 0; i < 5; ++i) {
        if (a[i] == 0) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}
