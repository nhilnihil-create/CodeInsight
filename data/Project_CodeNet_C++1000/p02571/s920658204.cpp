#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S, T;
  cin >> S >> T;

  int ans = T.size();
  for (int i = 0; i <= S.size() - T.size(); i++) {
    int diff = 0;
    rep(j, T.size()) {
      if (T[j] != S[i + j]) diff++;
    }
    ans = min(ans, diff);
  }
  cout << ans << endl;
  return 0;
}