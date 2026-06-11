#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int MAXV = MAXN * MAXN;
const int INF = (1 << 30);
int ID[MAXN][MAXN];
vector<int> to[MAXV];
vector<int> from[MAXV];

int id(int a, int b)
{
  if (a > b)
    swap(a, b);
  return ID[a][b];
}

void initID(int N)
{
  int id = 0;
  for (int a = 0; a < N - 1; a++)
  {
    for (int b = a + 1; b < N; b++)
    {
      ID[a][b] = id;
      id++;
    }
  }
}

bool visited[MAXV];
int dp[MAXV];
int dfs(int v)
{
  if (visited[v])
  {
    if (dp[v] > 0)
      return dp[v];
    else
      return INF;
  }
  visited[v] = true;
  int ret = 0;
  for (auto u : to[v])
  {
    ret = max(ret, dfs(u));
  }
  return dp[v] = ret + 1;
}

int main()
{
  int N, a;
  cin >> N;
  int V = N * (N - 1) / 2;
  vector<vector<int>> A(N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1; j++)
    {
      cin >> a;
      a--;
      A[i].push_back(a);
    }
  }
  initID(N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1; j++)
    {
      if (j != 0)
      {
        from[id(i, A[i][j])].push_back(id(i, A[i][j - 1]));
      }
      if (j != N - 2)
      {
        to[id(i, A[i][j])].push_back(id(i, A[i][j + 1]));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < V; i++)
  {
    int ret = dfs(i);
    if (ret >= INF)
    {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, ret);
  }
  cout << ans << endl;
}