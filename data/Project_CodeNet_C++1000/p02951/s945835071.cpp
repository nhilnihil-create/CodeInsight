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

int main(void) {
    Int a, b,  c;
    cin >> a >> b >> c;
    if (c < a - b) {
        cout << 0 << endl;
    } else {
        cout << c - a + b << endl;
    }
    return 0;
}

