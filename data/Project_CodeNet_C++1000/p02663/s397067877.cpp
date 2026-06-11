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
    Int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    cout << (h2 - h1) * 60 + (m2 - m1) - k << endl;
    return 0;
}
