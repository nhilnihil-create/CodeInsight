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
    VI p(n);
    for (Int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    Int result = 0;
    Int min_left = LLONG_MAX;
    for (Int i = 0; i < n; ++i) {
        if (p[i] <= min_left) {
            ++result;
            min_left = p[i];
        }
    }
    cout << result << endl;
    return 0;
}

