#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<float> a(n);
  rep(i, n) cin >> a[i];
  float ans;
  rep(i, n) ans += 1.0 / a[i];
  ans = 1.0 / ans;
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}