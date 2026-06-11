#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int x, n;
  cin >> x >> n;
  if (n == 0)
  {
    cout << x << endl;
    return 0;
  }
  vector<int> a(102, 0);
  for (int i = 0; i < n; i++)
  {
    int p;
    cin >> p;
    a[p]++;
  }
  int tmp = 101;
  int ans = 0;
  for (int i = 101; i >= 0; i--)
  {
    if (a[i] == 0)
    {
      int buf = abs(x - i);
      if (buf <= tmp)
      {
        tmp = buf;
        ans = i;
      }
    }
  }
  cout << ans << endl;
}
