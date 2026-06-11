#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> table(n+1, 0);

  rep(j, k) {
    rep(i, n+1) table[i] = 0;

    rep(i, n) {
      table[max(0ll, i-a[i])]++;
      table[min(n, i+a[i]+1)]--;
    }

    rep(i, n) {
      if (0 < i) table[i] += table[i-1];
    }

    bool flag = true;
    rep(i, n) {
      if (a[i] != table[i]) {
        flag = false;
        break;
      }
    }
    if (flag) break;

    rep(i, n) a[i] = table[i];
  }

  rep(i, n) cout << a[i] << " ";
  cout << endl;

  return 0;
}
