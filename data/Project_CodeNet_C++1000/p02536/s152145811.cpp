
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 100000;

vector<int> adj[MAX_N + 1];

bool visited[MAX_N + 1];

void dfs(int u) {
   visited[u] = true;
   for (int v : adj[u]) {
      if (!visited[v]) dfs(v);
   }
}

int main() {

   int n, m;
   scanf("%d %d", &n, &m);
   for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
   }
   int ans = 0;
   for (int i = 1; i <= n; i++) {
      if (visited[i]) continue;
      ans++;
      dfs(i);
   }
   printf("%d\n", ans - 1);

   return 0;
}

