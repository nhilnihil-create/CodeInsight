#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  sort(ALL(a));

  vector<P> ans;
  FOR(i, 1, n - 1) {
    if (a[i] <= 0) {
      ans.push_back(P(a[n - 1], a[i]));
      a[n - 1] -= a[i];
    } else {
      ans.push_back(P(a[0], a[i]));
      a[0] -= a[i];
    }
  }
  ans.push_back(P(a[n - 1], a[0]));

  cout << a[n - 1] - a[0] << endl;
  for (auto x : ans) {
    cout << x.first << " " << x.second << endl;
  }
  return 0;
}