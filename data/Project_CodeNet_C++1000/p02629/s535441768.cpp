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

string IntegerToNbaseString(Int base, Int target, char start_alphabet) {
    string s = "";
    while (target != 0) {
        Int quo = target / base;
        Int rem = target % base;
        if (rem == 0) {
            rem = base;
            --quo;
        }
        s += char(start_alphabet + rem - 1);
        target = quo;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(void) {
    Int n;
    cin >> n;
    cout << IntegerToNbaseString(26, n, 'a') << endl;
    return 0;
}

