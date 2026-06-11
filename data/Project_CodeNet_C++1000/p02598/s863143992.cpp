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
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    ll max_num = 0;
    rep(i, n) {
        cin >> a[i];
        max_num = max(max_num, a[i]);
    }
    if (k == 0) {
        cout << max_num << endl;
        return 0;
    }
    ll l = 0;
    ll r = 1e9;

    while(r-l>1LL) {
        ll m = (l + r) / 2LL;
        ll cnt = 0;
        rep(i, n) {
            cnt += (a[i] + m - 1LL) / m - 1LL; 
        }
        //cout << l << " " << r << " " << cnt << endl;
        if (cnt > k) {
            l = m;
        }
        else {
            r = m;
        }
    }
    cout << r << endl;
    return 0;
}
