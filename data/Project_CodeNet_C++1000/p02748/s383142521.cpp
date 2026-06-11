#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,k,t,f,q,j;
  cin >> n; cin >> m; cin >> k;
  vector<int> a; vector<int> b; vector<int> c; vector<int> prices;
  for (int i = 0; i < n; ++i)
  {
    cin >> t;
    a.push_back(t);
  }
  for (int i = 0; i < m; ++i)
  {
    cin >> t;
    b.push_back(t);
  }
  for (int i = 0; i < k; ++i)
  {
    cin >> f;
    cin >> q;
    cin >> j;
    prices.push_back(a[f-1]+b[q-1]-j);
  }
  sort(prices.begin(),prices.end());
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  cout << min(prices[0],a[0]+b[0]);
}