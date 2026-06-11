#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  for (int i = 0; i < n; i++) cin >> l[i];
  sort(l.begin(), l.end());

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int x = lower_bound(l.begin(), l.end(), l[i] + l[j]) - l.begin();
      ans += x - j - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
