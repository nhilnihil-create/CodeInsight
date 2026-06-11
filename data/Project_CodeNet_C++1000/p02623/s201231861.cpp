#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<ll> as(n+1), bs(m+1);
    rep(i,n) {
      as[i+1] = as[i]+a[i];
    }
    rep(i,m) {
      bs[i+1] = bs[i]+b[i];
    }
    int ans = 0;
    rep(i,n+1) {
      ll now = as[i];
      if (now > k) break;
      int j = upper_bound(bs.begin(), bs.end(), k-now) - bs.begin();
      j--;
      ans = max(ans, i+j);
    }
    cout << ans << endl;
    return 0;
}