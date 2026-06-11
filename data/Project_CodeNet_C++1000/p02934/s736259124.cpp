#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  double total = 0;
  rep(i, n) total += (double) 1.0000 / a[i];
  double ans = 1.0000 / total;
  cout << fixed << setprecision(10) << ans << '\n'; 
  return 0;
}