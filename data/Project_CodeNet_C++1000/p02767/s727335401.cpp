
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x

signed main() {
    capi(n);

    int ans = INT_MAX;
    vector<int> vx;
    rep(i, n) {
        capi(x);
        vx.push_back(x);
    }

    rep(i, 100) {
        int res = 0;
        for (auto x: vx) {
            res += (i + 1 - x) * (i + 1 - x);
        }

        ans = min(ans, res);
    }

    cout << ans;

    return 0;
}