#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  vector<int> ans(n, 1);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    if (h[a] >= h[b])
    {
      ans[b] = 0;
    }
    if (h[a] <= h[b])
    {
      ans[a] = 0;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (ans[i])
    {
      cnt++;
    }
  }
  cout << cnt << endl;
}
