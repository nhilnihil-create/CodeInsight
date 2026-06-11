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
  // vector<P> v(n);
  vector<pair<double,double>> v(n);
  rep(i, 0, n) {
    int x, l;
    cin >> x >> l;
    // v[i] = make_pair(x - l + 1, x + l - 1);
    v[i] = make_pair(x - l + 0.1, x + l - 0.1);
  }
  sort(v.begin(), v.end());

  int ans = 0;
  // P now = v[0];
  pair<double, double> now = v[0];
  rep(i, 1, n) {
    if (v[i].first <= now.second) {
      ans++;
      if (v[i].second < now.second) {
        now = v[i];
      }
    } else {
      now = v[i];
    }
  }

  cout << n - ans << endl;
}
