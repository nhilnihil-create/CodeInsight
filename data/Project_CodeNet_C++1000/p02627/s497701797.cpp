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
    char a;
    cin >> a;
    if (a >= 'A' && a <= 'Z') {
        cout << 'A' << endl;
    } else if (a >= 'a' && a <= 'z') {
        cout << 'a' << endl;
    }
    return 0;
}
