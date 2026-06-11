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
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, 60) {
        ll x = 0;
        rep(j, n) if (a[j]>>i&1) ++x;
        ll now = x * (n - x) % mod;
        rep(j, i) now = now * 2LL % mod;
        ans += now;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
