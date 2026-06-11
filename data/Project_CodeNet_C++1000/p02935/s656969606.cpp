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
    vector<double> v(n);
    for (Int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    double result = v[0];
    for (Int i = 1; i < n; ++i) {
        result += v[i];
        result /= 2.0f;
    }
    cout << result << endl;
    return 0;
}
