#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int a, b, h, m;
  cin >> a >> b >> h >> m;

  const double PI = 3.141592653589793;

  double degree = 30 * h + ((double)m / 2) - m * 6;
  double rad = degree * M_PI / 180;
  double ans = a * a + b * b - 2 * a * b * cos(rad);
  cout << fixed << setprecision(20) << sqrt(ans) << endl;
}
