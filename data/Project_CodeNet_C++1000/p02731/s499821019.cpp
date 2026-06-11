#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int l;
  cin >> l;
  double ans = pow(l / 3.0, 3);
  printf("%.8f\n", ans);
  return 0;
}