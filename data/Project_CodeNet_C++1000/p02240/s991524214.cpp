#include <bits/stdc++.h>
using namespace std;
#define NIL -1

// 頂点の個数
int n;
// 隣接リスト
vector<vector<int> > G(100000, vector<int>(0));
// 頂点のグループidを格納する配列
vector<int> color(100000, NIL);

// 深さ優先探索でuを含む連結成分をグループ(id)分け(uはグループ分けされていないと仮定)
void dfs(int u, int id)
{
  stack<int> S;
  S.push(u);
  color.at(u) = id;
  while (!S.empty())
  {
    int v = S.top();
    S.pop();
    for (int i = 0; i < G.at(v).size(); i++)
    {
      if (color.at(G.at(v).at(i)) == NIL)
      {
        // vの隣接頂点で未発見(idがない)のものをスタックに積んでidをつける
        S.push(G.at(v).at(i));
        color.at(G.at(v).at(i)) = id;
      }
    }
  }
}

void assignIds()
{
  int id = 1;
  for (int i = 0; i < n; i++)
  {
    if (color.at(i) == NIL)
    {
      dfs(i, id);
      id++;
    }
  }
}

int main()
{
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }

  assignIds();

  int q;
  cin >> q;
  vector<bool> ans(q);
  for (int i = 0; i < q; i++)
  {
    int u, v;
    cin >> u >> v;
    ans.at(i) = (color.at(u) == color.at(v));
  }

  for (int i = 0; i < q; i++)
  {
    if (ans.at(i))
    {
      cout << "yes" << endl;
    }
    else
    {
      cout << "no" << endl;
    }
  }
}
