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
    Int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    Int sum = a1 + a2 + a3;
    if (sum > 21) {
        cout << "bust" << endl;
    } else {
        cout << "win" << endl;
    }
    return 0;
}
