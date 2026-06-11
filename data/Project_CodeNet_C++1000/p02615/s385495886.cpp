#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

bool compare(pii a, pii b) { return a.first > b.first; }
int main() {
  int n;
  cin >> n;
  vector<pii> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = 0;
  }

  sort(a.begin(), a.end(), compare);

  for (int i = 0; i < n; i++) {
    a[i].second = (i == 0 ? 1 : 2);
  }

  int count = 0;

  ll ans = 0;
  int i = 0;

  while (1) {
    ans += a[i].first * a[i].second;
    count += a[i].second;

    if (count == n - 1) {
      break;
    }
    if (count == n) {
      ans -= a[i].first;
      break;
    }
    i++;
  }

  cout << ans << endl;
}