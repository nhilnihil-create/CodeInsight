/* Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/
#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define foref(i, a, b) for (int i = b - 1, to = a; i >= to; i--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<int, int> Pair;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<Long> v(n);
  fore(i, 0, n) cin >> v[i];
  Long ans = 0;
  int maxi = 0;
  fore(i, 0, n) {
    if (v[i] < maxi)
      ans += (maxi - v[i]);
    else
      maxi = v[i];
  }
  cout << ans << '\n';

  return 0;
}