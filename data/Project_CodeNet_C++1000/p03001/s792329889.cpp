#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll W, H, x, y;
  cin >> W >> H >> x >> y;
  double ans = (double)H*W*0.5;
  int m = 0;
  if (x*2 == W && y*2 == H) {
    m = 1;
  }
  printf("%f %d", ans, m);
  return 0;
}