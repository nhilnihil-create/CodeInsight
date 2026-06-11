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

  string s;
  ll k;
  cin >> s >> k;

  bool f = true;
  ll n = s.length();
  rep(i, n) {
    if (s[i] != s[0]) {
      f = false;
      break;
    }
  }
  if (f) {
    cout << n * k / 2 << '\n';
    return 0;
  }
  ll fi = 0, la = 0;
  ll ans = 0;
  if (s[0] == s[n - 1]) {
    while (s[fi] == s[0]) fi++;
    ans += fi / 2;
    while (s[n - 1 - la] == s[n - 1]) la++;
    ans += la / 2;
    ans += (fi + la) / 2 * (k - 1);
  }
  string u = s.substr(fi, n - fi - la) + 'A';
  char c = u[0];
  ll cnt = 0;
  rep(i, u.length()) {
    if (u[i] == c) cnt++;
    else {
      ans += cnt / 2 * k;
      c = u[i];
      cnt = 1;
    }
  }
  cout << ans << '\n';





  
  return 0;
}