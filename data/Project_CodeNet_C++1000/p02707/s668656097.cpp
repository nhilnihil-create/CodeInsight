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
    VI v(n);
    Int a;
    for (Int i = 2; i <= n; ++i) {
        cin >> a;
        a--;
        v[a]++;
    }
    for (Int i = 0; i < n; ++i) {
        cout << v[i] << endl;
    }
    return 0;
}
