#include <algorithm>
#include <iostream>
#include <vector>

int n, m, q;
std::vector<int> a, b, c, d;

int dfs(std::vector<int> A = std::vector<int>(1, 1), int ans = -1) {
  if ((int)A.size() == n + 1) {
    int now = 0;
    for (int i = 0; i < q; ++i) {
      if (A[b[i]] - A[a[i]] == c[i])
        now += d[i];
    }
    return std::max(ans, now);
  }

  A.push_back(A.back());
  while (A.back() <= m) {
    ans = dfs(A, ans);
    A.back()++;
  }

  return ans;
}

int main() {
  std::cin >> n >> m >> q;
  a = b = c = d = std::vector<int>(q);
  for (int i = 0; i < q; ++i)
    std::cin >> a[i] >> b[i] >> c[i] >> d[i];

  int ans = dfs();
  std::cout << ans << std::endl;
}
