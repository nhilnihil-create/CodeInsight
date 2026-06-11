#include <iostream>
#include <set>
#include <string>

int main(void) {
  std::string buf;
  std::set<std::string> S;
  int N;
  std::cin >> N;
  for (int c = 0; c < N; ++c) {
    std::cin >> buf;
    S.insert(buf);
  }
  std::cout << S.size();
  return 0;
}