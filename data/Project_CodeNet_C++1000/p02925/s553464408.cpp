#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

struct ordered_pair {
  int n_, n2_;
  explicit ordered_pair(int n): n_(n), n2_(n*2-3) {}
  int64_t operator()(int x, int y) const {
    int z = std::min(x, y);
    return z*(n2_-z)/2 + std::max(x, y) - 1;
  }
};

uint64_t getZ() {
  uint64_t v = 0; int c;
  while((c = getchar_unlocked()) >= '0') v=v*10+c-'0';
  return v;
}

template<int MAXV>
struct scc {
  std::vector<int> G[MAXV], rG[MAXV], vs;
  bool used[MAXV];
  int cmp[MAXV];
  scc() {}
  void dfs(int v) {
    used[v] = true;
    for(auto c: G[v]) if(!used[c]) dfs(c);
    vs.push_back(v);
  }
  void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for(auto c: rG[v]) if(!used[c]) rdfs(c, k);
  }
  int build(int V) {
    std::fill_n(used, V, false);
    vs.clear();
    for(int v = 0; v < V; ++v) if(!used[v]) dfs(v);
    std::fill_n(used, V, false);
    int k = 0;
    for(int i = vs.size()-1; i >= 0; --i) {
      if(!used[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
  }
  void add_edge(int fr, int to) {
    G[fr].push_back(to); rG[to].push_back(fr);
  }
};

int const MAXN = 1000;
int const MAXV = MAXN*(MAXN-1)/2;

scc<MAXV> S;
int depth[MAXV];
int calc_depth(int v) {
  if(depth[v] >= 0) return depth[v];
  int res = -1;
  for(auto c: S.G[v]) res = std::max(res, calc_depth(c));
  ++res;
  return depth[v] = res;
}

int main() {
  int N = getZ(), maxv = N*(N-1)/2;
  ordered_pair P(N);
  for(int i = 0; i < N; ++i) {
    int pV = P(i, getZ()-1);
    for(int j = 1; j < N-1; ++j) {
      int cV = P(i, getZ()-1);
      S.add_edge(pV, cV);
      pV = cV;
    }
  }
  if(S.build(maxv) < maxv) fin(-1);
  std::fill_n(depth, maxv, -1);
  int ans = 0;
  for(int i = 0; i < maxv; ++i) {
    ans = std::max(ans, calc_depth(i)+1);
  }
  fin(ans);
  return 0;
}
