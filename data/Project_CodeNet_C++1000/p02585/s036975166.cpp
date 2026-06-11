#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const ll INF = 1e16;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n), c(n);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
  }

  rep(i, n) cin >> c[i];

  ll ans = -1e18;
  rep(si, n) {
    int x = si;
    vector<int> s;
    ll total = 0;
    while (1) {
      total += c[x];
      s.push_back(c[x]);
      x = p[x];
      if (x == si) break;
    }

    ll cur = 0;
    int m = s.size();
    rep(i, m) {
      if (i + 1 > k) break;
      cur += s[i];
      ll t = cur;
      if (total > 0) t += ((k - (i + 1)) / m) * total;
      ans = max(ans, t);
    }
  }

  cout << ans << endl;

}