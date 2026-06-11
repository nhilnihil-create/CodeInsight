#include <iostream>
#include <algorithm>
#include <queue>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define outl(x) cout<< (x) << '\n'
using namespace std;
using let = const int;

int V, E;
bool vis[10005];
vector <int> G[10005];
vector <int> out;

void bfs(let s, int *indeg)
{
   queue <int> que; que.emplace(s);
   while (!que.empty()) {
      let u = que.front(); que.pop();
      out.emplace_back(u);
      for(let x : G[u]) if( --indeg[x] == 0 && !vis[x]++ ) que.emplace(x);
   }
}

void topologial_sort()
{
   static int indeg[10005] = {};
   rep(i, V)
      for(let x: G[i]) ++indeg[x];
   rep(i, V)
      if (indeg[i] == 0 && !vis[i]++) bfs(i, indeg);

   for_each(out.cbegin(), out.cend(), [](let x) { outl( x ); });
}

signed main()
{
   cin.tie(0), ios::sync_with_stdio(false);
   cin >> V >> E;

   while(E--) {
      int s, t;
      cin >> s >> t;
      G[s].emplace_back(t);
   }

   topologial_sort();
}


