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
i64 mod = 1000000007;
int int_max = 2147483647;
i64 INF = 1e16;
int max_n = 1e5;


int main(int argc, char **argv) {
    i64 n;
    cin >> n;

    vector<i64> as(n+1);
    i64 sum_a{0};
    for (int i=0; i<n+1; ++i) {
        cin >> as[i];
        sum_a += as[i];
    }

    if (n==0) {
        if (as[0]<2) cout << as[0] << endl;
        else cout << -1 << endl;
        return 0;
    }
    i64 ans{0}, level_nodes{1};

    for (int i=0; i<n+1; ++i) {
        sum_a -= as[i];

        if (as[i] > level_nodes) {
            cout << -1 << endl;
            return 0;
        }

        ans += level_nodes;

        if ((level_nodes-as[i]) < sum_a)
            level_nodes = min((level_nodes-as[i])*2, sum_a);
        else
            level_nodes = sum_a;
    }

    cout << ans << endl;

    return 0;
}
