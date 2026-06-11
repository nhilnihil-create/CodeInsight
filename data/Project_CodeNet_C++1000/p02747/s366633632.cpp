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
    string s;
    cin >> s;
    Int len = (Int)s.length();
    if (len % 2 == 1) {
        cout << "No" << endl;
    } else {
        bool result = true;
        for (Int i = 0; i < len; i += 2) {
            if (s[i] == 'h' && s[i + 1] == 'i') {
            } else {
                result = false;
            }
        }
        if (result) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
