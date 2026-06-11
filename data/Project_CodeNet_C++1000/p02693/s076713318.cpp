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
    Int k, a, b;
    cin >> k >> a >> b;
    Int aModK = a % k;
    Int bModK = b % k;
    if (b - a >= k) {
        cout << "OK" << endl;
    } else if (aModK == 0 || bModK == 0) {
        cout << "OK" << endl;
    } else if (aModK > bModK) {
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }
    return 0;
}
