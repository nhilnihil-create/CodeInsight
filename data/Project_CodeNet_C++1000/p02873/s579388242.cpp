#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  vector<int> v(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == '<') v[i + 1] = v[i] + 1;
  }
  long long ans = v[n];
  for (int i = n - 1; ~i; i--) {
    if (s[i] == '>') v[i] = max(v[i], v[i + 1] + 1);
    ans += v[i];
  }
  cout << ans;
  return 0;
}
