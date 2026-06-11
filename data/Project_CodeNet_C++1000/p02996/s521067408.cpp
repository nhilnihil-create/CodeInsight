#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  std::map<int, int> map;
  rep(i, n) {
    int ta, tb;
    std::cin >> ta >> tb;
    map[tb] += ta;
    a[i] = ta;
    b[i] = tb;
  }

  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());

  int sum = 0;
  for (auto i : b) {
    sum += map[i];
    if (sum > i) {
      std::cout << "No" << std::endl;
      return 0;
    }
  }

  std::cout << "Yes" << std::endl;
  return 0;
}
