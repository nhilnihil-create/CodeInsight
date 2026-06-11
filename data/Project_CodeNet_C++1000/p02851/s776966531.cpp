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
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
//i64 mod = 1000000007;
i64 mod = 998244353;
int int_max = 2147483647;
i64 INF = 1e16;
int max_n = 1e5;

int main(int argc, char **argv) {
    i64 n, k;
    cin >> n >> k;

    i64 ans{0};

    vector<i64> a0(n+1), as(n+1, 0);
    for (i64 i=1;i <n+1; ++i) {
        cin >> a0[i];
        as[i]=as[i-1]+a0[i];
    }

    map<i64, i64> search;
    for (int i=0; i<n+1; ++i) {
        if (i-k >= 0) {
            i64 ik = (as[i-k]-(i-k)) % k;
            --search[ik];
        }

        i64 ai = (as[i]-i) % k;
        auto it = search.find(ai);
        if (it != search.end()) {
            ans += it->second;
            ++(it->second);
        } else {
            search[ai] = 1;
        }
    }

    cout << ans << endl;

    return 0;
}