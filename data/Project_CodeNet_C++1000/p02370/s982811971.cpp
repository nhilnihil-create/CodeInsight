#include <cstdio>
#include <vector>

int main() {
  int V, E;
  scanf("%d%d", &V, &E);
  std::vector<std::vector<int>> edges(V, std::vector<int>());
  std::vector<int> cs(V, 0);
  for (int i = 0; i < E; i++) {
    int s, t;
    scanf("%d%d", &s, &t);
    edges[s].push_back(t);
    cs[t]++;
  }
  std::vector<int> todo;
  for (int v = 0; v < V; v++)
    if (cs[v] == 0)
      todo.push_back(v);
  while (todo.size()) {
    auto s = todo.back();
    todo.pop_back();
    printf("%d\n", s);
    for (auto&& t : edges[s]) {
      cs[t]--;
      if (cs[t] == 0)
        todo.push_back(t);
    }
  }
  return 0;
}