#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
using namespace std;
using namespace __gnu_pbds;
 
#define debug(s) cerr << #s << " = " << s << '\n'
#define all(v) (v).begin(), (v).end()
#define mem(a,val) memset(a, val, sizeof a)
 
#define ff first
#define ss second
typedef long long ll;
 
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N = 2010;
const int mod = 1e9 + 7;
int n, arr[N];
ll k, f[N], p[N];
ordered_set s;

ll bigmod(ll a, ll n, ll M) {
  ll res = 1LL;
  while (n) {
    if (n & 1) res = (res * a) % M;
    a = (a * a) % M;
    n >>= 1;
  }
  return res % M;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  int ptr = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    s.insert({arr[i], ptr++});
    p[i] = (i - s.order_of_key({arr[i] + 1, 0}));
  }
  for (int i = 1; i <= n; ++i) f[i] = (n - (s.order_of_key({arr[i] + 1, 0})));
  ll inv = bigmod(2, mod - 2, mod);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ll val = (k*(((2LL*p[i] + (k - 1)*f[i]) % mod)*inv % mod) % mod) % mod;
    ans = (ans + val) % mod;
  }
  cout << ans << '\n';
}