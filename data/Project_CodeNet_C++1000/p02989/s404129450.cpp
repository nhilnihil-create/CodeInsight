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
    VI d(n);
    for (Int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    cout << d[n / 2] - d[n / 2 - 1] << endl;
    return 0;
}
