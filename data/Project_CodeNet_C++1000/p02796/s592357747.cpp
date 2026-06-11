#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

struct R {
  int l, r;
  bool operator<(R const& rhs) const { return r < rhs.r; }
};
int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<R> rs(N);
  for(auto& rb: rs) {
    int X, L; std::cin >> X >> L;
    rb.l = X-L;
    rb.r = X+L;
  }
  std::sort(rs.begin(), rs.end());
  int ans = 1, last = rs[0].r;
  for(int i = 1; i < rs.size(); ++i) {
    if(rs[i].l < last) continue;
    ++ans;
    last = rs[i].r;
  }
  fin(ans);
  return 0;
}
