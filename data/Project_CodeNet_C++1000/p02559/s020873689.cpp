#include <iostream>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
using ll = long long;

int main()
{
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> ft(n);
  for (int i = 0; i < n; i++)
  {
    int ai;
    cin >> ai;
    ft.add(i, ai);
  }
  for (int j = 0; j < q; j++)
  {
    int qi;
    cin >> qi;
    if (qi == 0)
    {
      int p, x;
      cin >> p >> x;
      ft.add(p, x);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      cout << ft.sum(l, r) << endl;
    }
  }

  return 0;
}