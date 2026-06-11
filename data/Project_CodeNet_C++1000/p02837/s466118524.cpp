#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<vector<int>> x(n + 1);
  vector<vector<int>> y(n + 1);
  vector<int> a(n + 1);

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];

    x[i].resize(a[i] + 1);
    y[i].resize(a[i] + 1);
    for (int j = 1; j <= a[i]; j++)
    {
      cin >> x[i][j] >> y[i][j];
    }
  }

  int ans = 0;
  for (int mask = 1; mask < (1 << n); mask++)
  {

    bool ok = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
      //   if (!(mask & (1 << (i - 1))))
      if (!(mask >> (i - 1) & 1))
      {
        continue;
      }
      cnt++;
      for (int j = 1; j <= a[i]; j++)
      {
        // x[i][j]-1番目の人が正直ならビットは1なはず
        if (((mask >> (x[i][j] - 1)) & 1) ^ y[i][j])
        {
          ok = false;
        }
      }
    }

    if (ok)
    {
      ans = max(ans, cnt);
    }
  }

  cout << ans << endl;
  return 0;
}