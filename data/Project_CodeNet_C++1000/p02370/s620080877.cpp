#include <bits/stdc++.h>
using namespace std;
static const int WHITE = 0;
static const int GRAY = 1;

int V, E;
vector<vector<int> > G;
vector<int> color;
list<int> ans;
void init()
{
  G.resize(V);
  color.resize(V, WHITE);
}

void dfs(int u)
{
  color.at(u) = GRAY;
  for (int i = 0; i < G.at(u).size(); i++)
  {
    if (color.at(G.at(u).at(i)) == WHITE)
    {
      dfs(G.at(u).at(i));
    }
  }
  ans.push_front(u);
}

void topological_sort()
{
  for (int i = 0; i < V; i++)
  {
    if (color.at(i) == WHITE)
    {
      dfs(i);
    }
  }
}

int main()
{
  cin >> V >> E;
  init();
  for (int i = 0; i < E; i++)
  {
    int s, t;
    cin >> s >> t;
    G.at(s).push_back(t);
  }
  topological_sort();
  for (int i = 0; i < V; i++)
  {
    cout << ans.front() << endl;
    ans.pop_front();
  }
}
