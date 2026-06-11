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

ll pow(ll a, ll n) {
    ll ret = 1;
    while(1) {
        if (n == 0) break;
        if (n&1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> num(1e7+1, 1);
    for (int i = 2; i <= 1e7; ++i) {
        int idx = i;
        while(1) {
            if (idx > 1e7) break;
            ++num[idx];
            idx += i;
        }
    }
    // for (int i = 0; i <= 20; ++i) {
    //     cout << num[i] << " ";
    // }
    // cout << endl;
    // vector<ll> beki(64, 0);
    // rep(i, 64) beki[i] = pow(2LL, (ll)i);
    // for (int i = 0; i <= 20; ++i) {
    //     cout << beki[i] << " ";
    // }
    // cout << endl;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << beki[(ll)(num[i] - 1)] << " ";
        // ans += (ll)i * beki[(ll)(num[i] - 1)];
        ans += (ll)i * (ll)(num[i]);
    }
    cout << ans << endl;
    return 0;
}
