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

int main(void) {
    string s, t;
    cin >> s >> t;
    Int length = s .length();
    Int count = 0;
    for (Int i = 0; i < length; ++i) {
        if (s[i] == t[i]) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

