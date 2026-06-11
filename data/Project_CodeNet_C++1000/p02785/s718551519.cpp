#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> hs(n);
  rep(i, n) cin >> hs[i];
  sort(hs.begin(), hs.end());
  ll ans = 0;
  rep(i, n - k) ans += hs[i];
  cout << ans << endl;
  return 0;
}
