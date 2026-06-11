
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

    int ac = 1;
    int ans = 0;
    for (int ac = 1; n >= ac; ac *= k) {
        ++ans;
    }

    cout << ans;

    return 0;
}
