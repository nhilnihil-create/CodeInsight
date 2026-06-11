#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> accum(n+1, 0);
    rep(i, n) {
        cin >> a[i];
        accum[i+1] = accum[i] + a[i];
    }
    ll ans = 1e18;
    for (int i = 1; i <= n; ++i) {
        ll tmp_num1 = accum[n] - accum[i];
        ll tmp_num2 = accum[i];
        ans = min(ans, abs(tmp_num1 - tmp_num2));
    }
    cout << ans << endl;
    return 0;
}
