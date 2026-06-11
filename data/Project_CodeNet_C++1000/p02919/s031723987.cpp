#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1000000005;
const long double EPS = 1e-10;

int main() {
  int n;
  cin >> n;
  vector<ll> p(n + 2, INF);
  FOR(i, 1, n + 1) cin >> p[i];
  
  vector<ll> idx(n + 1);
  FOR(i, 1, n + 1) {
    idx[p[i]] = i;
  }

  ll ans = 0;
  set<ll> s;
  FORR(i, n, 1) {
    s.insert(idx[i]);

    vector<ll> a(2, 0), b(2, n + 1);
    auto itr = s.find(idx[i]);
    rep(j, 2) {
      if (itr == s.begin()) break;
      a[j] = *(--itr);
    }
    itr = s.find(idx[i]);
    rep(j, 2) {
      itr++;
      if (itr == s.end()) break;
      b[j] = *(itr);
    }

    ll c = (a[0] - a[1]) * (b[0] - idx[i]) + (b[1] - b[0]) * (idx[i] - a[0]);
    ans += c * i;
  }
  cout << ans << endl;


  
  return 0;
}