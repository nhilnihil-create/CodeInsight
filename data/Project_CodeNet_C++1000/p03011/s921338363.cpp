#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int p, q, r;
  cin >> p >> q >> r;
  cout << (p + q + r) - max({p, q, r}) << '\n';
  return 0;
}
