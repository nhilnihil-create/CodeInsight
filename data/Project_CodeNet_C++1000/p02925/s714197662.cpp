#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int MAXV = MAXN * (MAXN - 1) / 2;
vector<int64_t> to[MAXV];
int id[MAXN][MAXN];

int toId(int i, int j)
{
  if (i > j)
    swap(i, j);
  return id[i][j];
}

int dp[MAXV]; // max length if path from v
bool visited[MAXV];
bool calculated[MAXV];
int dfs(int v)
{
  if (visited[v])
  {
    if (!calculated[v])
      return -1;
    return dp[v];
  }
  visited[v] = true;
  dp[v] = 1;
  for (int u : to[v])
  {
    int res = dfs(u);
    if (res == -1)
      return -1;
    dp[v] = max(dp[v], res + 1);
  }
  calculated[v] = true;
  return dp[v];
}

int main()
{
  int64_t N;
  cin >> N;
  vector<vector<int64_t>> A(N, vector<int64_t>(N - 1));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1; j++)
    {
      cin >> A.at(i).at(j);
      A.at(i).at(j)--;
    }
  }
  int V = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i < j)
        id[i][j] = V++;
    }
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1; j++)
    {
      A[i][j] = toId(i, A[i][j]);
    }
    for (int j = 0; j < N - 2; j++)
    {
      to[A[i][j + 1]].push_back(A[i][j]);
    }
  }
  int ans = 0;
  for (int i = 0; i < V; i++)
  {
    int res = dfs(i);
    if (res == -1)
    {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
}
