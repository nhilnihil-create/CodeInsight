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
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<ll> suf(n+2);
    rep(i, n+1) cin >> a[i];

    if (n == 0) {
        if (a[0] == 1) {
            cout << 1 << endl;
            return 0;
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    if (a[0] > 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = n; i >= 0; --i) {
        suf[i] = suf[i+1] + a[i];
    }

    ll x = 1;
    ll ans = 1;

    for (int i = 1; i <= n; ++i) {
        if (x * 2 < a[i]) {
            cout << -1 << endl;
            return 0;
        }
        ll d = min(x*2, suf[i]);
        ans += d;
        x = d - a[i];
    }

    cout << ans << endl;


    return 0;
}
