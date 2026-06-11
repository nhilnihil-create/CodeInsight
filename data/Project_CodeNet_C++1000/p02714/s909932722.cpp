#include <array>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;

  // 累積
  std::vector<std::array<int, 3>> sum(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    int c;
    if (s[i] == 'R')
      c = 0;
    else if (s[i] == 'G')
      c = 1;
    else if (s[i] == 'B')
      c = 2;

    sum[i][c] = sum[i + 1][c] + 1;
    sum[i][(c + 1) % 3] = sum[i + 1][(c + 1) % 3];
    sum[i][(c + 2) % 3] = sum[i + 1][(c + 2) % 3];
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (s[i] == s[j])
        continue;

      int c;
      if (s[i] == 'R' && s[j] == 'G')
        c = 2;
      else if (s[i] == 'G' && s[j] == 'R')
        c = 2;
      else if (s[i] == 'G' && s[j] == 'B')
        c = 0;
      else if (s[i] == 'B' && s[j] == 'G')
        c = 0;
      else if (s[i] == 'B' && s[j] == 'R')
        c = 1;
      else if (s[i] == 'R' && s[j] == 'B')
        c = 1;

      res += sum[j + 1][c];

      int k = j + (j - i);
      if (k < n) {
        if (s[k] == 'R' && c == 0)
          res -= 1;
        if (s[k] == 'G' && c == 1)
          res -= 1;
        if (s[k] == 'B' && c == 2)
          res -= 1;
      }
    }
  }
  std::cout << res << std::endl;
}
