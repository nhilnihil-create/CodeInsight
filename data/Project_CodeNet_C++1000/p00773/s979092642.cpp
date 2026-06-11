#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (int i = (int)a; i < (int)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265359
#define EPS 1e-12

int main(void) {
  while (true) {
    int x, y, s;
    cin >> x >> y >> s;
    if(!x && !y && !s) break;

    int ret_x, ret_y, ans = -INF;
    FOR(i, 1, s) {
      int a = i - i * x / (100 + x), b = (s - i) - (s - i) * x / (100 + x);
      ret_x = a * (100 + x) / 100 + b * (100 + x) / 100;
      ret_y = a * (100 + y) / 100 + b * (100 + y) / 100;
      if (ret_x != s)
        continue;
      else
        ans = max(ans, ret_y);
    }

    cout << ans << endl;
  }
  return 0;
}