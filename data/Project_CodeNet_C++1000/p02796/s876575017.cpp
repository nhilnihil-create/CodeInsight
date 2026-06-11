#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int MAX = 10e9;

int main() {
  int n;
  cin >> n;
  vector<pint> v(n);
  rep(i, n) {
    int x, l;
    cin >> x >> l;
    v[i] = pint(x + l, x - l);
  }
  sort(v.begin(), v.end());

  int ans = 0;
  int now = MAX * -1;
  rep(i, n) {
    if (now > v[i].second) continue;
    ans++;
    now = v[i].first;
  }

  cout << ans << endl;
  return 0;
}
