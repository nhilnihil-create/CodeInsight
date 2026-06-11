#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
template <class t, class u>
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
void chmax(t& a, u b) {
  if (a < b) a = b;
}
ll f(int x) {
  if (x == -1) return 0;
  if (x == 0) return 0;
  if (x == 1) return 1;
  return x + f(x - 1);
}
int main() {
  string s;
  cin >> s;
  int n = s.size() + 1;
  vector<ll> a(n);
  REP(i, n - 1) {
    if (s[i] == '<') {
      chmax(a[i + 1], a[i] + 1);
    }
  }
  per(i, n - 1) {
    if (s[i] == '>') {
      chmax(a[i], a[i + 1] + 1);
    }
  }
  ll mx = 0;
  REP(i, n) mx += a[i];
  cout << mx << endl;
}