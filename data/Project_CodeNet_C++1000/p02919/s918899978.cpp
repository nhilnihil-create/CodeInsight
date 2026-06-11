#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> idx(n + 1);
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        idx[p] = i;
    }

    multiset<int> mset{0, 0, n + 1, n + 1};
    ll ans = 0;
    for (int i = n; i >= 1; --i) {
        int c = idx[i];
        auto it_d = mset.lower_bound(c);
        ll d = *it_d;
        ll e = *(++it_d);
        ll b = *(----it_d);
        ll a = *(--it_d);

        ans += ((e - d) * (c - b) + (b - a) * (d - c)) * (ll)i;

        mset.insert(c);
    }

    cout << ans << endl;
    return 0;
}