#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<P> v(n);
  rep(i, 0, n) cin >> v[i].second >> v[i].first;

  sort(v.begin(), v.end());
  int now = 0;
  rep(i, 0, n) {
    now += v[i].second;
    if (now > v[i].first) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
