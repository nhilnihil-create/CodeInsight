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
    Int a;
    string s;
    cin >> a >> s;
    if (a >= 3200) {
        cout << s << endl;
    } else {
        cout << "red" << endl;
    }
    return 0;
}

