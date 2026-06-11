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
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    ans = a[0];
    int idx = 1;
    int cnt = 1;
    while(1) {
        if (cnt == n - 1) break; 
        ans += a[idx];
        ++cnt;
        if (cnt&1) ++idx;
    }
    cout << ans << endl;
    return 0;
}
