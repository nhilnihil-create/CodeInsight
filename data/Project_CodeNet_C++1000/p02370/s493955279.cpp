#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <sstream>
#include <string>
#include <utility>
#include <map>
#include <memory>
#include <set>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class TSort
{
public:
  int solve();
  void dfs( vector<vector<int>>& adj, vector<bool>& vd, vector<int>& rt, int u );
};

int TSort::solve()
{
  int nv, ne;
  cin >> nv >> ne;

  vector<vector<int>> adj(nv);
  vector<bool> visited(nv, false);
  vector<int> ret;

  for ( auto i = 0; i < ne; ++i )
    {
      int s, t;
      cin >> s >> t;
      adj[s].push_back( t );
    }

  for ( auto i = 0; i < nv; ++i )
    {
      if ( ! visited[i] )
        dfs( adj, visited, ret, i );
    }

  for ( auto i = 0; i < nv; ++i )
    cout << ret[nv - 1 - i] << endl;
  
  return 0;
}

void TSort::dfs( vector<vector<int>>& adj, vector<bool>& vd, vector<int>& rt, int u )
{
  vd[u] = true;

  int n = adj[u].size();
  
  for ( auto i = 0; i < n; ++i )
    {
      int v = adj[u][i];
      
      if ( ! vd[v] )
        {
          dfs( adj, vd, rt, v );
        }
    }

  rt.push_back( u );
}

int main()
{
  TSort ts;

  ts.solve();

  return 0;
}