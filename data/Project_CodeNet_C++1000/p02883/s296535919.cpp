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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<int> f(n);
    rep(i, n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    ll l = -1, r = 1e18;
    while(r-l>1) {
        ll m = (r+l)/2LL;
        ll cnt = 0;
        rep(i, n) {
            if (a[i] * f[i] > m) {
                cnt += (a[i] * f[i] - m) / f[i];
                if ((a[i] * f[i] - m) % f[i]) ++cnt;
            }
        }
        if (cnt > k) l = m;
        else r = m;
    }
    cout << r << endl;
    return 0;
}
