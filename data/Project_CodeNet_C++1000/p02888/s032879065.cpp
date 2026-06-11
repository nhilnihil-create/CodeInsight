#include <bits/stdc++.h>
using namespace std;
bool Grid[55][55];

int main()
{
  int n;
  cin >> n;
  vector<int> ls(n);
  for (int i = 0; i < n; i++)
  {
    cin >> ls[i];
  }
  sort(ls.begin(), ls.end());
  int64_t ans = 0;
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      int a = ls[i], b = ls[j];
      int x = upper_bound(ls.begin() + (j + 1), ls.end(), b - a) - ls.begin();
      int y = lower_bound(ls.begin() + (j + 1), ls.end(), a + b) - ls.begin();
      ans += (y - x);
    }
  }
  cout << ans << endl;
}