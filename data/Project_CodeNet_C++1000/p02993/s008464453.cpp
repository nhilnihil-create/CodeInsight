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
    if ((s[0] == s[1]) || (s[1] == s[2]) || (s[2] == s[3])) {
        cout << "Bad" << endl;
    } else {
        cout << "Good" << endl;
    }
    return 0;
}

