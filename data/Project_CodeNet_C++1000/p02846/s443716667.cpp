#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    lint T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    lint D = (A1 * T1 + A2 * T2) - (B1 * T1 + B2 * T2);
    if (D == 0) {
        cout << "infinity\n";
        return 0;
    }
    if (D < 0) {
        swap(A1, B1);
        swap(A2, B2);
        D = -D;
    }
    if (A1 * T1 > B1 * T1 && D > 0) {
        cout << 0 << "\n";
        return 0;
    }
    lint ans = 1;
    lint S = B1 * T1 - A1 * T1;
    if (S % D == 0) {
        ans += (S / D - 1) * 2;
        ans += 1;
    } else {
        ans += S / D * 2;
    }
    cout << ans << "\n";
    return 0;
}
