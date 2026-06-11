#include <iostream>
#include <vector>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

int main()
{
  int n, q;
  cin >> n >> q;
  dsu G(n);
  for (int qi = 0; qi < q; qi++)
  {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0)
    {
      G.merge(u, v);
    }
    else
    {
      cout << (G.same(u, v) ? 1 : 0) << endl;
    }
  }

  return 0;
}