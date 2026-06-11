#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 200005

int parent[MAX_SIZE];

int Find(int x) {
  if (parent[x] == -1) {
    return x;
  }
  return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  int px = Find(x), py = Find(y);
  if (px != py) {
    parent[py] = px;
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  memset(parent, -1, sizeof(parent));

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    Union(x, y);
  }

  unordered_map<int, int> group;
  for (int i = 1; i <= n; ++i) {
    group[Find(i)]++;
  }

  int ans = 0;
  for(const auto& p : group) {
    if (p.second > ans) {
      ans = p.second;
    }
  }

  printf("%d\n", ans);
  return 0;
}