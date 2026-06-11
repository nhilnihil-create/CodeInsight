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
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end(), greater<ll>());
  ll ans = p;
  ll cnt1 = n, cnt2 = 0;
  ll sum = 0;
  FOR(i, p, n) {
    cnt1--, cnt2++;
    sum += a[i - 1];
    if (a[p - 1] > a[i] + m) break;
    ll res = cnt1 * m + (a[i] + m) * cnt2 - sum;
    if (res < m * v) break;
    ans++;
  }
  cout << ans << '\n';




  
  return 0;
}