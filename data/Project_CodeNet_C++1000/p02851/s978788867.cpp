#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n + 1);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.at(i + 1) = (s.at(i) + a - 1) % k;
  }
  map<int, int> m;
  int64_t ans = 0;
  for (int i = 0; i <= n; i++) {
    if (i >= k) m[s[i - k]]--;
    ans += m[s[i]];
    m[s[i]]++;
  }
  cout << ans << endl;
}
