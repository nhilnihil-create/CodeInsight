#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++)
  {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  int ans;
  if (d[n / 2] == d[n / 2 - 1])
  {
    ans = 0;
  }
  else
  {
    ans = d[n / 2] - d[n / 2 - 1];
  }
  cout << ans << endl;
}
