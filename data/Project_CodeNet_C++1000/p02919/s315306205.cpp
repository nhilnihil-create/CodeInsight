#include<iostream>
#include<numeric>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

uint64_t getZ() {
  uint64_t v = 0; int c;
  while((c = getchar_unlocked()) >= '0') v=v*10+c-'0';
  return v;
}

int const MAXN = 2e5;
int P[MAXN];

int main() {
  int N = getZ();
  for(int i = 0; i < N; ++i) P[i] = getZ();
  std::vector<int> ix(N);
  std::iota(ix.begin(), ix.end(), 0);
  std::sort(ix.begin(), ix.end(), [&](int l, int r){ return P[l] > P[r]; });
  int64_t ans = 0;
  std::multiset<int> S;
  S.insert(-1); S.insert(-1); S.insert(N); S.insert(N);
  for(auto i: ix) {
    int64_t p = P[i];
    auto it = S.lower_bound(i);
    int il1 = *--it, il2 = *--it;
    it = S.upper_bound(i);
    int ir1 = *it++, ir2 = *it;
    ans += p*((il1-il2)*(ir1-i) + (i-il1)*(ir2-ir1));
    S.insert(i);
  }
  fin(ans);
  return 0;
}
