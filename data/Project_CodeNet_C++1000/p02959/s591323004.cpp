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
    VI a(n + 1), b(n);
    for (Int i = 0; i < n + 1; ++i) {
        cin >> a[i];
    }
    for (Int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    Int result = 0;
    for (Int i = 0; i < n; ++i) {
        if (a[i] + a[i + 1] < b[i]) {
            result += (a[i] + a[i + 1]);
            a[i] = 0;
            a[i + 1] = 0;
        } else if (a[i] < b[i]) {
            result += b[i];
            a[i + 1] -= (b[i] - a[i]);
            a[i] = 0;
        } else {
            result += b[i];
            a[i] -= b[i];
        }
    }
    cout << result << endl;
    return 0;
}
