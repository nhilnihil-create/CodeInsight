#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  double sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += (double)1 / a[i];
  }
  double ans = (double)1 / sum;
  if (float(ans) == ans)
  {
    cout << ans << endl;
  }
  else
  {
    cout << fixed << setprecision(14) << (double)1 / sum << endl;
  }
}
