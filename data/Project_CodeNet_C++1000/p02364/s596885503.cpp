#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

const int MAX_N = 202020;
const ll INF = 1LL<<60;

int n, m;
ll sum;
vector<pair<ll, P>> G;
vector<P> mst;

struct UnionFind {
  vector<int> data;
  
  UnionFind(int sz)
  {
    data.assign(sz, 0);
    for(int i = 0; i < sz; i++) data[i] = i;
  }
  
  int root(int x)
  {
    if(data[x] == x) return x;
    else return data[x] = root(data[x]);
  }
  
  bool unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if(x == y) return false;
    data[x] = y;
  }
  
  bool same(int x, int y)
  {
    return root(x) == root(y);
  }
};

void kruskal()
{
  UnionFind uf(n);
  sum = 0;
  for(auto e : G)
  {
    ll cost = e.first;
    int from = e.second.first, to = e.second.second;
    if(!uf.same(from, to))
    {
      uf.unite(from, to);
      sum += cost;
      mst.emplace_back(P(from, to));
    }
  }
}

void init()
{
  cin >> n >> m;
  rep(i,m)
  {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    G.emplace_back(pair<ll, P>(c, P(a, b)));
  }
  sort(G.begin(), G.end());
  
  return;
}

void put()
{
  cout << sum << endl;
  return;
}

int main()
{
  init();
  kruskal();
  put();
  return 0;
}
