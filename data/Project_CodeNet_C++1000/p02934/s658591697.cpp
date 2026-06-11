#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n;
  cin >> n;
  double ans = 0;
  rep(i, n)
  {
    double a;
    cin >> a;
    ans += 1 / a;
  }
  printf("%.6lf\n", 1 / ans);
  return 0;
}