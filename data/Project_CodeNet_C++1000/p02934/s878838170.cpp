#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cout << fixed << setprecision(10);
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  double sum = 0;
  for (int i = 0; i < n; ++i) {
    double a;
    cin >> a;

    sum += 1.0 / a;
  }

  cout << 1.0 / sum << endl;

  return (0);
}
