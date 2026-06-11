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
    vector<pair<ll, ll>> v(n);
    rep(i, n) {
        ll x, l;
        cin >> x >> l;
        v[i] = make_pair(x+l, x-l);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    ll now = -1e18;
    rep(i, n) {
        if (now <= v[i].second) {
            ++ans;
            now = v[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}
