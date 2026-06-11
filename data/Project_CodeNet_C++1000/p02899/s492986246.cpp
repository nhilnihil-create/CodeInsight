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
    Int a;
    for (Int i = 0; i < n; ++i) {
        cin >> a;
        a--;
        mp[a] = i + 1;
    }
    for (Int i = 0; i < n; ++i) {
        cout << mp[i] << " ";
    }
    cout << endl;
    return 0;
}
