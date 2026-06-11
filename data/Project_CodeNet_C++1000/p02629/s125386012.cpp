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
    Int n;
    cin >> n;
    string s = "";
    while (n != 0) {
        Int quo = n / 26;
        Int rem = n % 26;
        if (rem == 0) {
            rem = 26;
            --quo;
        }
        s += char('a' + rem - 1);
        n = quo;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}

