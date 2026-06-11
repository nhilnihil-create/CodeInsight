#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];

  // counting vector
  std::vector<int> c;
  {
    std::map<int, int> mp;
    for (auto v : a)
      mp[v] += 1;
    for (auto kv : mp)
      c.push_back(kv.second);
  }
  std::sort(c.begin(), c.end());

  // area vector
  std::vector<long long> s(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    // #{j; c[j] >= i}
    int d = c.end() - std::lower_bound(c.begin(), c.end(), i);
    s[i] = s[i - 1] + d;
  }

  for (long long k = 1; k <= n; ++k) {
    int ok = 0;
    int ng = n + 1;
    while (ng - ok > 1) {
      int mid = ok + (ng - ok) / 2;
      if (k * mid <= s[mid]) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    std::cout << ok << std::endl;
  }

  return 0;
}
