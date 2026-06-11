/*input
10 58
9 1 6 7 8 4 3 2 10 5
695279662 988782657 -119067776 382975538 
-151885171 -177220596 -169777795 37619092 
389386780 980092719
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), c(n);
    rep(i, n) cin >> p[i], --p[i];
    rep(i, n) cin >> c[i];
    ll ans = c[0];
    rep(i, n) {
        int prv = i, rl = 0;
        ll rs = 0;
        do {
            rl++;
            rs += c[prv = p[prv]];
        } while (prv != i);
        int mj = min(rl, k);
        rs = max(rs, 0LL);
        ll s = 0;
        prv = i;
        for (int j = 1; j <= mj; j++) {
            s += c[prv = p[prv]];
            ans = max(ans, s+(k-j)/rl*rs);
        }
    }
    cout << ans << endl;
}