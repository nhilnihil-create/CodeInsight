#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

// input
uint64_t getZ() {
  uint64_t v = 0; int c;
  while((c = getchar_unlocked()) >= '0') v=v*10+c-'0';
  return v;
}

int const MAXN = 1e5;
std::pair<int, int> BA[MAXN];

int main() {
  int N = getZ(), M = getZ();
  for(int i = 0; i < N; ++i) {
    BA[i].second = getZ();
    BA[i].first = getZ();
  }
  std::sort(BA, BA+N,
    [&](auto const& l, auto const& r){ return l.second < r.second; });
  std::priority_queue<std::pair<int,int>> q;
  int ans = 0, p = 0;
  for(int d = 1; d <= M; ++d) {
    while(p < N && BA[p].second <= d) q.push(BA[p++]);
    if(!q.empty()) {
      ans += q.top().first;
      q.pop();
    }
  }
  fin(ans);
  return 0;
}
