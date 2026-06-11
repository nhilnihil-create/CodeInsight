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
    VI a(n), b(n);
    for (Int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    if (b[n - 2] == b[n - 1]) {
        for (Int i = 0; i < n; ++i) {
            cout << b[n - 1] << endl;
        }
    } else {
        for (Int i = 0; i < n; ++i) {
            if (a[i] == b[n - 1]) {
                cout << b[n - 2] << endl;
            } else {
                cout << b[n - 1] << endl;
            }
        }
    }
    return 0;
}
