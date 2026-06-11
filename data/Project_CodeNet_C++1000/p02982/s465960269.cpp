#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < d; j++)
    {
      cin >> x[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      double buf = 0;
      for (int k = 0; k < d; k++)
      {
        int tmp = abs(x[i][k] - x[j][k]);
        buf += pow(tmp, 2);
      }
      buf = sqrt(buf);
      if (float(buf) == buf)
      {
        ans++;
      }
    }
  }

  cout << ans << endl;
}
