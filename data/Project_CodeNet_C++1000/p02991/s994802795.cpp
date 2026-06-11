#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, m)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
  }
  int s, t;
  cin >> s >> t;
  s--;
  t--;
  vector<vector<bool>> chk(n, vector<bool>(3, false));
  queue<pair<int, int>> q;
  q.emplace(0, s);
  while (!q.empty())
  {
    auto p = q.front();
    q.pop();
    int count = p.first;
    int crt = p.second;
    if (chk[crt][count%3])
      continue;
    chk[crt][count%3] = true;
    if (count % 3 == 0 && crt == t)
    {
      cout << count / 3 << endl;
      return 0;
    }
    for (int i : g[crt])
      q.emplace(count + 1, i);
  }
  cout << -1 << endl;
  return 0;
}