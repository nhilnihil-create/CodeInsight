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
    string s;
    cin >> s;

    Int result = 0;
    char c = ' ';
    Int length = s.length();
    for (Int i = 0; i < length; ++i) {
        if (c != s[i]) {
            result++;
            c = s[i];
        }
    }
    cout << result << endl;
    return 0;
}
