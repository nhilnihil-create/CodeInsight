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
    bool z_flg = false;
    rep(i, n) {
        cin >> a[i];
        if (a[i] == 0) z_flg = true;
    }
    if (z_flg) {
        cout << 0 << endl;
        return 0;
    } 
    ll lim = 1e18;
    ll m = a[0];
    for (int i = 1; i < n; ++i) {
        if (lim / a[i] < m) {
            cout << -1 << endl;
            return 0;
        }
        m *= a[i];
    }
    cout << m << endl;
    return 0;
}
