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
  int X; cin >> X;
  int tmp;
  int ans = 0;
  tmp = X / 500; ans += tmp * 1000; X -= tmp * 500;
  tmp = X / 5; ans += tmp * 5; X-= tmp * 5;
  cout << ans << endl;
}