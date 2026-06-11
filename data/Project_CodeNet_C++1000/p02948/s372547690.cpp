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
    i64 n,m;
    cin >> n >> m;

    priority_queue<P, vector<P>, greater<P>> mp;
    priority_queue<i64> q;

    for (i64 i=0; i<n; ++i) {
        i64 a, b;
        cin >> a >> b;
        mp.push(make_pair(a,b));
    }
    i64 ans{0};
    for (i64 i=1; i<=m; ++i) {
        while (! mp.empty()) {
            P p = mp.top();
            if (p.first <= i) {
                mp.pop();
                q.push(p.second);
            } else {
                break;
            }
        }
        if (q.empty()) continue;
        ans += q.top(); q.pop();
    }

    cout << ans << endl;
    return 0;
}