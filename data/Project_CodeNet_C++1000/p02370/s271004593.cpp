#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>

const int vmax = 10005;
std::array<std::vector<int>, vmax> adjlist;
std::array<int, vmax> indeg;
std::array<int, vmax> color;

void dfs (int u)
{
  if (indeg[u] == 0 && color[u] ==0)
    {
      std::cout << u << std::endl;
      color[u] = 1;
      for (int i=0; i<adjlist[u].size(); ++i)
        {
          indeg[adjlist[u][i]]--;
          dfs(adjlist[u][i]);
        }
    }
}

void dfs_stack (int u)
{
  std::stack<int> s;
  s.push(u);

  while (!s.empty())
    {
      u = s.top();
      s.pop();

      if (indeg[u] == 0 && color[u] ==0)
        {
          std::cout << u << std::endl;
          color[u] = 1;
          for (int i=0; i<adjlist[u].size(); ++i)
            {
              indeg[adjlist[u][i]]--;
              s.push(adjlist[u][i]);
            }
        }
    }
}

int main ()
{
  int V, E;
  std::cin >> V >> E;

  indeg.fill(0);
  int s, t;
  for (int i=0; i<E; ++i)
    {
      std::cin >> s >> t;
      adjlist[s].push_back(t);
      indeg[t]++;
    }

  color.fill(0); // 0: not visited, 1: visited

  for (int i=0; i<V; ++i)
    {
      // dfs(i);
      dfs_stack(i);
    }
}



