#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }

  int cnt = 0;
  sort(l.begin(), l.end());
  for (int x = 0; x < n - 2; x++) {
    for (int y = x + 1; y < n - 1; y++) {
      auto iter = upper_bound(l.begin() + y + 1, l.end(), l[x] + l[y] - 1);
      cnt += (int)distance(l.begin() + y + 1, iter);
    }
  }

  cout << cnt << '\n';
  return 0;
}
