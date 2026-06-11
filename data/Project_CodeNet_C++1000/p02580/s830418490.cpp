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
const int INF = 1e9;
const int MX = (3e5);
Long T[1LL << 20];
Long N = 1;
void update(Long pos, Long val) {
  pos += N;
  T[pos] += val;
  while (pos > 0) {
    pos >>= 1;
    T[pos] = max(T[2 * pos], T[2 * pos + 1]);
  }
}
Long query(Long l, Long r) {
  l += N;
  r += N;
  Long ans = 0;
  while (l < r) {
    //cout << l << " " << r << endl;
    if (l & 1) ans = max(ans, T[l++]);
    if (r & 1) ans = max(ans, T[--r]);
    l >>= 1;
    r >>= 1;
  }
  return ans;
}
map<Long, vector<Long>> px, py;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  while (N < m) N <<= 1;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    px[a].pb(b);
    py[b].pb(a);
    update(b, +1);
  }
  Long ans = 0;
  fore(i, 0, MX) {
    //fijo el I, entonces la respuesta actual es
    Long cur = SZ(px[i]);
    for (Long x : px[i]) {
      update(x, -1);
    }
    cur += query(0, MX);
    ans = max(ans, cur);
    for (Long x : px[i]) {
      update(x, +1);
    }
  }
  cout << ans << '\n';

  return 0;
}