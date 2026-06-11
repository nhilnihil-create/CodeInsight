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
    capi(h);
    int ans = 0;
    for (int i = 1; h > 0;) {
        ans += i;
        h /= 2;
        i *= 2;
    }
    
    cout << ans;

    return 0;
}