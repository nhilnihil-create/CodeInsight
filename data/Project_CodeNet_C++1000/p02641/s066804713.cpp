#include <iostream>
#include <set>

int X, N;

int main() {
  std::cin >> X >> N;
  std::set<int> P;
  for (int i = 0; i < N; ++i) {
    int x;  std::cin >> x;
    P.insert(x);
  }

  if (P.find(X) == P.end())
    std::cout << X << "\n";
  else {
    int left = X, right=X;
    while (P.find(left) != P.end())
      left--;
    while (P.find(right) != P.end())
      right++;
    std::cout << (X - left <= right - X ? left : right) << "\n";
  }

  return 0;
}
