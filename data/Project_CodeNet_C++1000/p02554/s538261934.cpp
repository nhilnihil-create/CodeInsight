#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

typedef long long llong;
typedef unsigned long long ullong;
// -2.1e-9 <= int <= 2.1e9
// -9.2e-18 <= long long <= 9.2e18
// 0 <= unsigned int <= 4.2e9
// 0 <= unsigned long long <= 18.4e18
// cout << fixed << setprecision(10);

int main() {
    ullong Q = static_cast<ullong>(1e9 + 7);
    ullong N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    ullong not0 = 1, not0and9 = 1;
    ullong total = 1;
    for (uint i=1; i<=N; ++i) {
        not0 *= 9;
        not0 %= Q;
        not0and9 *= 8;
        not0and9 %= Q;

        total *= 10;
        total %= Q;
    }
    ullong not0or9 = (not0 + not0 + Q - not0and9) % Q;
    ullong ans = (total + Q - not0or9) % Q;
    cout << ans << endl;
}

