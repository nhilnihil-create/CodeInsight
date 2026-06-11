#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll w, h, x, y;
  cin >> w >> h >> x >> y;
  double g = w * h / 2.0;
  int m = w/2.0 == x && h/2.0 == y ? 1 : 0;
  cout << g << " " << m << endl;
  return 0;
}