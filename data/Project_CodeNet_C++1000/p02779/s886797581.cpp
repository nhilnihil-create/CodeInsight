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
    Int n;
    cin >> n;
    map<Int, Int> mp;
    bool result = true;
    Int a;
    for (Int i = 0; i < n; ++i) {
        cin >> a;
        if (mp[a] != 0) {
            result = false;
        } else {
            mp[a] = 1;
        }
    }
    if (result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

