#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }
  vector<int> per(n);
  for (int i = 0; i < n; i++) {
    per[i] = i + 1;
  }
  int cnt = 0, pi = 0, qi = 0;
  do {
    cnt++;
    if (per == p) pi = cnt;
    if (per == q) qi = cnt;
  } while (next_permutation(per.begin(), per.end()));
  cout << abs(pi - qi) << '\n';
  return 0;
}
