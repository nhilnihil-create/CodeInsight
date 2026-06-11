#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n, d;

  cin >> n >> d;
  int ans = 0;

  double x, y;
  rep(i, n)
  {
    cin >> x >> y;
    double dis = sqrt(x * x + y * y);
    if (d >= dis)
      ans++;
  }
  cout << ans;
}
