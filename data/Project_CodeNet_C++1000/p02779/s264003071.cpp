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

    set<int> s;
    rep(i, n) {
        capi(a);
        s.insert(a);
    }

    if (s.size() == n) cout << "YES";
    else cout << "NO";

    return 0;
}