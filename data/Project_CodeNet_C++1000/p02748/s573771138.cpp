#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b, m;
  cin >> a >> b >> m;
  vector<int> c1(a + 1), c2(b + 1);
  for (int i = 1; i <= a; i++) {
    cin >> c1[i];
  }
  for (int i = 1; i <= b; i++) {
    cin >> c2[i];
  }
  int mn1 = c1[1], mn2 = c2[1];
  for (int i = 1; i <= a; i++) {
    mn1 = min(mn1, c1[i]);
  }
  for (int i = 1; i <= b; i++) {
    mn2 = min(mn2, c2[i]);
  }
  int ans = mn1 + mn2;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    ans = min(ans, c1[x] + c2[y] - z);
  }
  cout << ans << '\n';
} 