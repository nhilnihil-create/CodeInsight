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

const static UInt MOD = 1e9 + 7;

int main(void) {
    Int n, m;
    cin >> n >> m;
    VI stairs(n + 1);
    for (Int i = 0; i <= n; ++i) {
        stairs[i] = 0;
    }
    Int broken;
    for (Int i = 0; i < m; ++i) {
        cin >> broken;
        stairs[broken] = -1;
    }
    if (n == 1) {
        if (m == 1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        stairs[0] = 0;
        if (stairs[1] != -1) {
            stairs[1] = 1;
        } else {
            stairs[1] = 0;
        }
        if (stairs[2] != -1) {
            stairs[2] = stairs[1] + 1;
        } else {
            stairs[2] = 0;
        }
        for (Int i = 3; i <= n; ++i) {
            if (stairs[i] == -1) {
                stairs[i] = 0;
            } else {
                stairs[i] = ((stairs[i - 1] + stairs[i - 2]) % MOD);
            }
        }
        cout << stairs[n] << endl;
    }
    return 0;
}
