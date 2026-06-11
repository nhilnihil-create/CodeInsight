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
    vector<ll> a(n+1), b(n);
    rep(i, n+1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    vector<ll> aa = a;
    rep(i, n) {
        if (a[i] > b[i]) {
            //cout << "test1" << endl;
            ans += b[i];
            a[i] -= b[i];
        }
        else {
            //cout << "test2" << endl;
            ans += a[i];
            ans += min(a[i+1], (b[i] - a[i]));
            //cout << b[i] - a[i] << endl;
            a[i+1] = max(0LL, a[i+1] - b[i] + a[i]);
            a[i] = 0;
        }
        //cout << ans << endl;
    }
    reverse(aa.begin(), aa.end());
    reverse(b.begin(), b.end());
    ll cnt = 0;
    rep(i, n) {
        if (aa[i] > b[i]) {
            //cout << "test1" << endl;
            cnt += b[i];
            aa[i] -= b[i];
        }
        else {
            //cout << "test2" << endl;
            cnt += aa[i];
            cnt += min(aa[i+1], (b[i] - aa[i]));
            //cout << b[i] - aa[i] << endl;
            aa[i+1] = max(0LL, aa[i+1] - b[i] + aa[i]);
            aa[i] = 0;
        }
    }
    ans = max(ans, cnt);
    cout << ans << endl;
    return 0;
}
