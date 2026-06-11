#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x[100], y[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (atan2(y[i], x[i]) > atan2(y[j], x[j]))
      {
        swap(x[i], x[j]);
        swap(y[i], y[j]);
      }

  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    int sumX = 0, sumY = 0;
    for (int j = 0; j < n; j++)
    {
      sumX += x[(i + j) % n];
      sumY += y[(i + j) % n];
      ans = max(ans, 1LL * sumX * sumX + 1LL * sumY * sumY);
    }
  }

  cout << fixed << setprecision(12) << sqrt(ans) << endl;
}
