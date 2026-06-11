
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
    int n, k;
    cin >> n >> k;

    vector<int> v;
    rep(i, n) {
        capi(h);
        v.push_back(h);
    }

    sort(all(v));

    int ans = 0;
    rep(i, n - k) {
        ans += v[i];
    }

    cout << ans;

    return 0;
}
