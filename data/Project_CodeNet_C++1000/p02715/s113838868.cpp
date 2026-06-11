#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define pii pair<int, int>
#define All(x) (x).begin(), (x).end()
#define mp make_pair
#define Task "abc"

typedef long long ll;
const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;

ll f[maxn], cnt[maxn];

ll Pow(ll x, ll y){
  if (y == 0) return 1;
  ll tmp = Pow(x, y / 2);
  tmp = tmp * tmp; tmp %= mod;
  if (y % 2) return (tmp * x) % mod;
  return tmp;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(NULL);
//  freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
  int n, k; cin >> n >> k;

  for (int i = 1; i <= k; ++i)
    for (int j = i; j <= k; j += i) ++cnt[i];

  ll ans = 0;
  for (int i = k; i > 0; --i){
    f[i] = Pow(cnt[i], n);
    for (int j = i * 2; j <= k; j += i) {
      f[i] = f[i] - f[j] + mod;
      f[i] %= mod;
    }
    ans = ans + f[i] * i;
    ans = ans % mod;
  }
  cout << ans;

return 0;
}
