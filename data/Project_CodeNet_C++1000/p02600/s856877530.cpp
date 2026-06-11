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
    Int x;
    cin >> x;
    Int score[9] = {400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000};
    for (Int i = 0; i < 9; ++i) {
        if (x < score[i]) {
            cout << 9 - i << endl;
            break;
        }
    }
    return 0;
}
