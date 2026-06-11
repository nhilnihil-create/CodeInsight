#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
typedef complex<double> cd;
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s; cin >> s;
  int n = s.size();
  ll k; cin >> k;

  int need = 0;
  for(int i = 1; i < n; ++i) {
    if(s[i] == s[i - 1]) {
      ++need;
      ++i;
    }
  }
  if(k == 1) {
    cout << need << endl;
    return 0;
  }

  bool only = 1;
  for(int i = 1; i < n; ++i) {
    if(s[i] != s[i - 1]) {
      only = 0;
      break;
    }
  }
  if(only) {
    ll cnt = n * k;
    ll ans = cnt / 2;
    cout << ans << endl;
    return 0;
  }

  s += s;
  n = s.size();
  int needTwice = 0;
  for(int i = 1; i < n; ++i) {
    if(s[i] == s[i - 1]) {
      ++needTwice;
      ++i;
    }
  }

  ll diff = needTwice - need;
  ll ans = need + (k - 1) * diff;
  cout << ans << endl;
}
