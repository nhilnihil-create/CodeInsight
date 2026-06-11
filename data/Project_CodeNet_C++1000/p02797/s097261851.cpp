#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, k, s;
  std::cin >> n >> k >> s;
  std::vector<int> a(n);

  rep(i, n) {
    if (i < k) {
      a[i] = s;
    } else {
      if (s == 1)
        a[i] = s + 1;
      else
        a[i] = s - 1;
    }
  }
  rep(i, n) {
    if (i > 0)
      std::cout << " ";
    std::cout << a[i];
  }
  std::cout << std::endl;

  return 0;
}
