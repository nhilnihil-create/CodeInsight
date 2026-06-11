#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  FOR(i, 1, n + 1) cin >> a[i];

  rep(i, n) {
    a[i + 1] = (a[i + 1] - 1 + a[i] + k) % k;
  }
  map<ll, ll> m;
  ll ans = 0;
  rep(i, n + 1) {
    if (i >= k) m[a[i - k]]--;
    ans += m[a[i]]++;
  }
  cout << ans << endl;


  
  return 0;
}