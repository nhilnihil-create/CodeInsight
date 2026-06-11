#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

vector<vector<int>> g, e;
int mx = 0;
void dfs(int pre, int crt)
{
  int c = 0;
  for (auto nxt : g[crt])
  {
    if (e[nxt][2] != 0)
      continue;
    c++;
    if (c == pre)
      c++;
    e[nxt][2] = c;
    dfs(c, e[nxt][0] != crt ? e[nxt][0] : e[nxt][1]);
  }
  mx = max(mx, c);
}

int main()
{
  int n;
  cin >> n;
  g.resize(n);
  e.resize(n - 1);

  rep(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(i);
    g[b].push_back(i);
    e[i].resize(3);
    e[i][0] = a;
    e[i][1] = b;
  }
  dfs(0, 0);
  cout << mx << endl;
  rep(i, n - 1)
    printf("%d\n", e[i][2]);
  return 0;
}