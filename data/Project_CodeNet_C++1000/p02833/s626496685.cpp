#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
//i64 mod = 998244353;
int int_max = 2147483647;
i64 INF = 1e16;
int max_n = 1e5;

int main(int argc, char **argv) {
    i64 n;
    cin >> n;

    if (n%2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    i64 ans{0};
    for (i64 i=10; i<=n; i*=5) {
        ans += n/i;
    }

    cout << ans << endl;

    return 0;
}
