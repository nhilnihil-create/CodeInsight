#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int cal(int a, int b) {
  return (b - a) / 2;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  if (a > b) swap(a, b);
  int ans = 0;
  if ((b - a) % 2 == 0) ans = cal(a, b);
  else {
    int r = n - b + 1;
    ans = min(cal(1, b - a) + a, cal(a + r, n) + r);
  }
  cout << ans << '\n';
}
