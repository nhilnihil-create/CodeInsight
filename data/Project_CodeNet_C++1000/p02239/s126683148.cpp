#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#define MAX 1000
#define INFTY 1<<30 // 2^30
using namespace std;
typedef long long llong;

static const int N = 100;

int n, M[N][N];
int d[N];

int bfs(int s)
{
  queue<int> q;
  q.push(s);
  for(int i = 0; i < n; i++) d[i] = INFTY;
  d[s] = 0;
  int u;
  while(!q.empty())
  {
    u = q.front(); q.pop();
    for(int v = 0; v < n; v++)
    {
      if(M[u][v] == 0) continue; // if not connect
      if(d[v] != INFTY) continue; // if have reached
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
  for(int i = 0; i < n; i++)
    cout << i+1 << " " << ((d[i] == INFTY) ? (-1) : d[i]) << endl;
}

int main()
{
  int u, k, v;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> u >> k;
    u--;
    for(int j = 0; j < k; j++)
    {
      cin >> v;
      v--;
      M[u][v] = 1;
    }
  }
  bfs(0);
}