#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

int const MAXN = 2e5;

std::vector<int> G[MAXN];
std::map<std::pair<int,int>, int> m;
int N, color[MAXN];

void dfs(int v, int p) {
  int pc = 0;
  if(p >= 0) pc = color[m[std::make_pair(v, p)]];
  int col = 1;
  for(auto c: G[v]) if(c != p) {
    if(col == pc) ++col;
    color[m[std::make_pair(c, v)]] = col;
    ++col;
    dfs(c, v);
  }
}

int main() {
  std::cin >> N;
  for(int i = 0; i < N-1; ++i) {
    int a, b; std::cin >> a >> b; --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
    m[std::make_pair(a, b)] = i;
    m[std::make_pair(b, a)] = i;
  }
  dfs(0, -1);
  int K = 0;
  for(int i = 0; i < N-1; ++i) K = std::max(K, color[i]);
  std::cout << K << std::endl;
  for(int i = 0; i < N-1; ++i) std::cout << color[i] << std::endl;
  return 0;
}
