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
    int len = (Int)s.length();
    if (s[len - 1] == '3') {
        cout << "bon" << endl;
    }
    else if ((s[len - 1] == '0') || (s[len - 1] == '1') || (s[len - 1] == '6') || (s[len - 1] == '8')) {
        cout << "pon" << endl;
    } else {
        cout << "hon" << endl;
    }
    return 0;
}
