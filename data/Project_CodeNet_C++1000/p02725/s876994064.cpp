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
    Int k, n;
    cin >> k >> n;
    VI a(n);
    VI d(n);
    for (Int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (Int i = 0; i < n - 1; ++i) {
        d[i] = a[i + 1] - a[i];
    }
    d[n - 1] = a[0] + k - a[n - 1];
    sort(d.begin(), d.end());

    Int result = 0;
    for (Int i = 0; i < n - 1; ++i) {
        result += d[i];
    }
    cout << result << endl;
    return 0;
}

