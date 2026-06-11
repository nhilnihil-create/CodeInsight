#include<iostream>
#include<vector>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  int n; std::cin >> n;
  std::vector<int> p(n);
  for(auto& v: p) std::cin >> v;
  int ans = 0;
  for(int i = 1; i < n-1; ++i) {
    if((p[i] < p[i-1]) != (p[i] < p[i+1])) ++ans;
  }
  fin(ans);
  return 0;
}
