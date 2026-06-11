#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
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
    Int x, n;
    cin >> x >> n;
    vector<Int> p(n);
    for (Int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<Int> s;
    vector<Int> b;
    bool x_exist = false;
    for (Int i = 0; i < n; ++i) {
        if (p[i] < x) {
            s.push_back(x - p[i]);
        } else if (p[i] > x) {
            b.push_back(p[i] - x);
        } else {
            x_exist = true;
        }
    }
    sort(s.begin(), s.end());
    sort(b.begin(), b.end());
    Int small_diff = -1;
    Int big_diff = -1;;
    for (Int i = 0; i < (Int)s.size(); ++i) {
        if (s[i] != i + 1) {
            small_diff = i + 1;
            break;
        }
    }
    if (small_diff == -1) {
        small_diff = (Int)s.size() + 1;
    }
    for (Int i = 0; i < (Int)b.size(); ++i) {
        if (b[i] != i + 1) {
            big_diff = i + 1;
            break;
        }
    }
    if (big_diff == -1) {
        big_diff = (Int)b.size() + 1;
    }
    //cout << small_diff << " " << big_diff << endl;

    if (!x_exist) {
        cout << x << endl;
    } else if (small_diff <= big_diff) {
        cout << x - small_diff << endl;
    } else {
        cout << x + big_diff << endl;
    }

    return 0;
}

