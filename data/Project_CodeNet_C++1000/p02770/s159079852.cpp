//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define trav(x,a) for (const auto& x: a)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), x.end()
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int _i = 0; _i < (n); _i++) ni(a[_i])
#define nal(a, n) for (int _i = 0; _i < (n); _i++) nl(a[_i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e6 + 5;
const double eps = 1e-9;
int d[N];

int main() {
  int k, q; scanf("%d %d", &k, &q);
  for (int i = 0; i < k; i++)
    scanf("%d", &d[i]);
  for (int i = 1; i <= q; i++) {
    int n, x, m; scanf("%d %d %d", &n, &x, &m);
    ll sm = 0;
    for (int j = 0; j < k; j++)
      sm += d[j] % m;
    x %= m;
    ll ans = 0;
    if (n <= k) {
      int a = x;
      for (int j = 1; j < n; j++) {
        int b = (a + d[(j - 1) % k]) % m;
        if (a < b)
          ans++;
        a = b;
      }
    } else {
      int r = n % k;
      if (n % k == 0)
        r += k, n -= k;
      ll z = x + (n/k) * 1ll * sm;
      for (int j = 1; j < r; j++)
        z += d[(j - 1) % k] % m;
      ans = z / m;
      for (int j = 0; j < k; j++) if (d[j] % m == 0)
        ans += (j+1 < r) + (n / k);
      if (r == k)
        n += k;
      ans = n - ans - 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
