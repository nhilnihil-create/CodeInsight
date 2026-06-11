#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s;
  std::cin >> s;
  int n = s.size();
  std::vector<int64_t> v(n + 1, 0);

  rep(i, n) {
    if (s[i] == '<') {
      v[i + 1] = v[i] + 1;
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    {
      if (s[i] == '>') {
        v[i] = max(v[i], v[i + 1] + 1);
      }
    }
  }

  int64_t ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += v[i];
  }

  std::cout << ans << std::endl;
  return 0;
}
