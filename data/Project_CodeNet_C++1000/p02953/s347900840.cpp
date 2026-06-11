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
    VI h(n);
    for (Int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    bool result = true;
    for (Int i = n - 2; i >= 0; --i) {
        if (h[i] <= h[i + 1]) {
        } else if (h[i] == h[i + 1] + 1) {
            h[i]--;
        } else {
            result = false;
        }
    }
    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
