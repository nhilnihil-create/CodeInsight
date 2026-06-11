#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n - 1));
  rep(i, n)
    rep(j, n - 1)
    {
      cin >> a[i][j];
      a[i][j]--;
    }
  vector<vector<int>> idx(n, vector<int>(n, -1));
  int id = 0;
  rep(i, n)
    rep(j, n)
    {
      if (i == j || idx[i][j] != -1)
        continue;
      idx[i][j] = idx[j][i] = id;
      id++;
    }
  vector<vector<int>> g(id);
  vector<int> indegree(id, 0);
  rep(i, n)
    rep(j, n - 2)
    {
      g[idx[i][a[i][j]]].push_back(idx[i][a[i][j+1]]);
      indegree[idx[i][a[i][j+1]]]++;
    }
  vector<int> day(id, 1);
  queue<int> q;
  rep(i, id)
    if (indegree[i] == 0)
      q.push(i);
  while (!q.empty())
  {
    int pre = q.front();
    q.pop();
    for(auto& nxt : g[pre])
    {
      if (--indegree[nxt] == 0)
        q.push(nxt);
      day[nxt] = max(day[nxt], day[pre] + 1);
    }
  }
  rep(i, id)
    if (indegree[i] != 0)
    {
      puts("-1");
      return 0;
    }
  int ans = 0;
  rep(i, id)
    ans = max(ans, day[i]);
  cout << ans << endl;
  return 0;
}