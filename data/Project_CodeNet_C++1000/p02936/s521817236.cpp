#include <bits/stdc++.h>
#define rep(i, n, s) for (int i = 0; i < n; i += s)
#define graph map<int, vector<int>>
#define field vector<vector<int>>
using namespace std;
typedef long long ll;

int dfs(vector<bool> &seen, graph &G, int &v, int &cnt, vector<ll> &point, vector<ll> &ans)
{
  seen[v] = true; // v を訪問済にする
  // v から行ける各頂点 next_v について
  cnt += point[v];
  ans[v] = cnt;
  for (auto next_v : G[v])
  {
    if (seen[next_v])
      continue;                            // next_v が探索済だったらスルー
    dfs(seen, G, next_v, cnt, point, ans); // 再帰的に探索
  }
  cnt -= point[v];
  return 0;
}
int main()
{
  int n, q;
  cin >> n >> q;
  graph g;
  rep(i, n-1, 1)
  {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  vector<ll> score(n, 0);
  rep(i, q, 1)
  {
    int p, x;
    cin >> p >> x;
    score[p - 1] += x;
  }
  vector<ll> ans(n, 0);
  vector<bool> seen(n, false);
  int vi = 0;
  int ct = 0;
  dfs(seen,g,vi,ct,score,ans);
  rep(i, n, 1)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}