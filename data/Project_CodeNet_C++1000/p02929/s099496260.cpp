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

  ll n;
  string s;
  cin >> n >> s;

  if (s[0] != 'B' || s[2 * n - 1] != 'B') {
    cout << 0 << '\n';
    return 0;
  }
  vector<ll> cnt(2, 0), a(2 * n, 0);
  cnt[1] = 1, a[0] = 1;
  FOR(i, 1, 2 * n) {
    if (s[i - 1] != s[i]) a[i] = a[i - 1];
    else a[i] = a[i - 1] ^ 1;
    cnt[a[i]]++;
  }
  if (cnt[0] != cnt[1]) {
    cout << 0 << '\n';
    return 0;
  }
  ll ans = 1, res = 0;
  rep(i, 2 * n) {
    if (a[i]) res += a[i];
    else {
      ans = ans * res % mod;
      res--;
    }
  }
  FOR(i, 1, n + 1) ans = ans * i % mod;
  cout << ans << '\n';



  
  
  



  



  

  
  return 0;
}