#include <bits/stdc++.h>
#include <bits/stdint-intn.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::map<uint64_t, uint64_t> map;
  rep(i, n) {
    int tmp;
    std::cin >> tmp;
    a[i] = tmp;
    map[tmp]++;
  }

  int64_t sum = 0;
  for (auto i : map) {
    sum += i.second * (i.second - 1) / 2;
  }

  rep(i, n) {
    int64_t before = map[a[i]] * (map[a[i]] - 1) / 2;
    int64_t after = (map[a[i]] - 1) * (map[a[i]] - 2) / 2;
    std::cout << (sum - before + after) << std::endl;
  }

  return 0;
}
