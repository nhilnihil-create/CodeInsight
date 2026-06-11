#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  const double pi = acos(-1);
  // double theta = max(h * 30, m * 6) - min(h * 30, m * 6);

  double theta = h * 30 + m * 0.5 - m * 6;

  theta = theta >= 180 ? 360 - theta : theta;

  // cout << theta << endl;

  theta = (theta / 180) * pi;
  // cout << theta << endl;

  double ans = a * a + b * b - 2 * a * b * cos(theta);

  printf("%.17lf\n", sqrt(ans));
}