#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i];
  }
  int cnt = 0;
  double ans = 0;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
  {
    p[i] = i;
  }

  do
  {
    for (int i = 0; i < n - 1; i++)
    {
      double dx = x[p[i]] - x[p[i + 1]];
      double dy = y[p[i]] - y[p[i + 1]];
      ans += sqrt(dx * dx + dy * dy);
    }
    cnt++;
  } while (next_permutation(p.begin(), p.end()));

  cout << fixed << setprecision(10) << ans / cnt << endl;
}
