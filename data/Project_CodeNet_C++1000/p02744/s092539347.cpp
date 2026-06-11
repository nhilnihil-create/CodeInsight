#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

void nextv(std::vector<std::string>const& in,
           std::vector<std::string>& out) {
  out.clear();
  for(auto s: in) {
    char mc = 'a';
    for(auto c: s) mc = std::max(mc, c);
    ++mc;
    for(char c = 'a'; c <= mc; ++c) out.push_back(s+c);
  }
}

int main() {
  int N; std::cin >> N;
  std::vector<std::string> v1, v2;
  v1.push_back("a");
  while(--N > 0) { nextv(v1, v2); v1.swap(v2); }
  for(auto s: v1) std::cout << s << std::endl;
  return 0;
}
