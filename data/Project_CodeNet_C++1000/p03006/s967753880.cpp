#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<P> v(n);
  rep(i, 0, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());

  map<P, int> mp;
  rep(i, 0, n) {
    rep(j, i + 1, n) {
      P p = make_pair(v[j].first - v[i].first, v[j].second - v[i].second);
      mp[p]++;
    }
  }

  int ans = 0;
  for (auto m : mp)
    chmax(ans, m.second);
  cout << n - ans << endl;
}
