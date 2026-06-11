#include <iostream>

const int MAXN = (int)1e6 + 1;

int count[MAXN];

int solve(int n) {
  int ans = 0;
  for (int i = 2; i < MAXN; ++i) {
    int num_of_mul = 0;
    for (int j = i; j < MAXN; j += i) {
      num_of_mul += count[j];
    }
    if (num_of_mul == n) return 2;
    if (num_of_mul > 1) ans = 1;
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0, in; i < n; ++i) {
    std::cin >> in;
    ++count[in];
  }

  int ans = solve(n);
  if (ans == 0) {
    std::cout << "pairwise coprime" << std::endl;
  } else if (ans == 1) {
    std::cout << "setwise coprime" << std::endl;
  } else {
    std::cout << "not coprime" << std::endl;
  }

  return 0;
}
