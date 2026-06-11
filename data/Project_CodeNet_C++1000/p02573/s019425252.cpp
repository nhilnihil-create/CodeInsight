#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> par;  // 親の番号

// n要素で初期化
void init(int n)
{
  par.resize(n);
  for (int i = 0; i < n; i++)
  {
    par[i] = i;
  }
}

int root(int x)
{
  if (par[x] == x)
  {
    return x;  // 根
  }
  else
  {
    return par[x] = root(par[x]);  // 経路圧縮
  }
}

// 同じ集合か？
bool same(int x, int y)
{
  return root(x) == root(y);
}

// xとyの属する集合を併合
void unite(int x, int y)
{
  x = root(x);
  y = root(y);
  if (x == y)
    return;

  par[x] = y;  // xの値をyに更新
}

int main()
{
  int n, m;
  cin >> n >> m;

  init(n);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    a--;
    b--;

    unite(a, b);
  }

  // 経路圧縮漏れが出ているから、再度ルール
  for (int i = 0; i < n; i++)
  {
    root(i);
  }

  // for (int i = 0; i < n; i++)
  // {
  //   cout << i << "," << par[i] << endl;
  // }

  vector<int> _size(n);

  // size
  for (int i = 0; i < n; i++)
  {
    _size[par[i]]++;
  }

  // for (int i = 0; i < n; i++)
  // {
  //   cout << _size[i] << endl;
  // }

  auto it = max_element(_size.begin(), _size.end());

  cout << *it << endl;
  return 0;
}