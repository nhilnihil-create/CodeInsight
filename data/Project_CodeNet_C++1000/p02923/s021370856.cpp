#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> hs(n);
  vector<int> cnts(n, 0);
  rep(i, n) cin >> hs[i];
  cnts[n - 1] = 0;
  int ans = 0;
  for (int i = n - 2; 0 <= i; i--) {
    if (hs[i + 1] <= hs[i]) {
      cnts[i] += cnts[i + 1] + 1;
      ans = max(cnts[i], ans);
    }
  }
  cout << ans << endl;
  return 0;
}
