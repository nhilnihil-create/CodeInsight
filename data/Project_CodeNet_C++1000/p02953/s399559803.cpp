#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> hs(n);
  cin >> hs[0];
  hs[0]--;
  bool ok = true;
  for (int i = 1; i < n; i++) {
    cin >> hs[i];
    ll d = hs[i] - hs[i - 1];
    if (1 <= d) {
      hs[i]--;
    } else if (d == 0) {
    } else {
      ok = false;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
