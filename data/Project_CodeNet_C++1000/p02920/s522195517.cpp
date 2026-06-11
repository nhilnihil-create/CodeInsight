#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

uint64_t getZ() {
  uint64_t v = 0; int c;
  while((c = getchar_unlocked()) >= '0') v=v*10+c-'0';
  return v;
}

int main() {
  int N = getZ();
  int p2N = 1<< N;
  std::multiset<int, std::greater<int>> S;
  std::vector<int> X;
  for(int i = 0; i < p2N; ++i) S.insert(getZ());
  p2N = 1;
  X.push_back(*S.begin());
  S.erase(S.begin());
  for(int i = 0; i < N; ++i) {
    std::sort(X.begin(), X.end(), std::greater<int>());
    for(int j = 0; j < p2N; ++j) {
      auto it = S.upper_bound(X[j]);
      if(it == S.end()) fin("No");
      X.push_back(*it);
      S.erase(it);
    }
    p2N *= 2;
  }
  fin("Yes");
  return 0;
}
