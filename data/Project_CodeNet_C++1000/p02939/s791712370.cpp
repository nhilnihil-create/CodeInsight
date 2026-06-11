#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  auto solve = [&](int init) {
    int cur = init, ans = 1, prev_len = init;
    while (cur < s.size()) {
      if (prev_len == 2 || s[cur] != s[cur - 1]) {
        cur++;
        ans++;
        prev_len = 1;
        continue;
      }

      if (cur == s.size() - 1) {
        break;
      }

      cur += 2;
      ans++;
      prev_len = 2;
    }

    return ans;
  };

  cout << max(solve(1), solve(2)) << '\n';
  return 0;
}
