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
const int INF = 1000000005;
const long double EPS = 1e-10;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> c(n);
  rep(i, n) c[--a[i]]++;

  vector<ll> d(n);
  rep(i, n) d[c[i]]++;

  vector<int> f(n + 1);
  f[0] = INF;
  ll sum = 0, psum = n;
  FOR(i, 1, n + 1) {
    psum -= d[i - 1];
    sum += psum;
    f[i] = sum / i;
  }

  vector<int> ans(n + 1);
  int idx = n;
  FOR(i, 1, n + 1) {
    while (i > f[idx]) {
      idx--;
    }
    ans[i] = idx;
  }
  FOR(i, 1, n + 1) cout << ans[i] << endl;






  
  return 0;
}