#include <algorithm>
#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::map<std::string, int> m;
  for (int i = 0; i < n; ++i) {
    std::string t;
    std::cin >> t;
    std::sort(t.begin(), t.end());
    ++m[t];
  }
  long sum = 0;
  for (auto i : m) {
    long c = i.second;
    sum += c * (c - 1) / 2;
  }

  std::cout << sum << std::endl;
}
	
