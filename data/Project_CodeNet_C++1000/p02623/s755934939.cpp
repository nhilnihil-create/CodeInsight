#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll LINF = 1001002003004005006LL;
const int INF = 1001001001;

const int mod = 1000000007;

int main() {
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    vector<ll> acum(n+1);
    vector<ll> bcum(m+1);
    rep(i,n) acum[i+1] = acum[i] + a[i];
    rep(i,m) bcum[i+1] = bcum[i] + b[i];
    int ans = 0;
    rep(i,n+1) {
        ll r = k - acum[i];
        if (r >= 0) {
            auto itr = upper_bound(all(bcum), r);
            int j = itr - bcum.begin()-1;
            ans = max(ans, i+j);
        }
    }
    cout << ans << endl;
    return 0;
}