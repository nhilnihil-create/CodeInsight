#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int ans = 1e9;
  for (int i = x[0]; i <= x[n - 1]; i++)
  {
    int buf = 0;
    for (int j = 0; j < n; j++)
    {
      buf += pow(x[j] - i, 2);
    }
    ans = min(ans, buf);
  }

  cout << ans << endl;
}
