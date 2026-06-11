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
    string s;
    cin >> s;
    map<char, int> mp;
    Int length = s.length();
    for (Int i = 0; i < length; ++i) {
        mp[s[i]]++;
    }
    bool result = true;
    for (Int i = 0; i < length; ++i) {
        if (mp[s[i]] != 2) {
            result = false;
        }
    }
    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

