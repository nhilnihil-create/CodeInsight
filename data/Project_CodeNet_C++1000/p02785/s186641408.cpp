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
    Int n, k;
    cin >> n >> k;
    VI h(n);
    for (Int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    Int result = 0;
    for (Int i = 0; i < n - k; ++i) {
        result += h[i];
    }
    cout << result << endl;
    return 0;
}

