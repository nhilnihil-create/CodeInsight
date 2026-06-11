#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());
  ll ans = 0;
  vector<int> b = {0, a[n - 1]};
  for (int i = 1; i < n; ++i) rep(j, 2) b.push_back(a[n - 1 - i]);
  for (int i = 0; i < n; ++i) ans += b[i];

  cout << ans << endl;

  return 0;
}