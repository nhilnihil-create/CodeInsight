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

    vector<ll> asum(n+1);
    vector<ll> bsum(m+1);
    rep(i,n) asum[i+1] = asum[i]+a[i];
    rep(i,m) bsum[i+1] = bsum[i]+b[i];

    int ans = 0;
    rep(i,n+1) {
        if (asum[i]>k) break;
        ll r = k-asum[i];
        auto itr = upper_bound(all(bsum), r);
        int bsize = itr-bsum.begin()-1;
        //cout << "i: " << i << " asize: " << i << " bsize: " << bsize << endl;
        ans = max(ans, i+bsize);
    }
    cout << ans << endl;
    return 0;
}