#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef tree< ll, null_type, less< ll >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll mod;

ll pwr(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(0);cin.tie(0);

  ll n, p;
  cin >> n >> p;
  string s;
  cin >> s;

  mod = p;

  if(10 % p == 0){
    ll ans = 0;
    for(int i = 0; i < n; i++){
      if((s[i] - '0') % p == 0) ans += i + 1;
    }
    cout << ans << endl;
    return 0;
  }

  vector < ll > dp(p, 0);
  ll x = 0, ans = 0;
  dp[0] = 1;
  for(int i = 0; i < n; i++){
    ll num = s[i] - '0';
    x = (10 * x + num) % p;
    ll val = x * pwr(10, n - i - 1);
    val %= p;
    //ans += dp[x];
    dp[val]++;
  }

  for(int i = 0; i < p; i++){
    if(dp[i] >= 2) ans += (dp[i] * (dp[i] - 1)) / 2;
  }

  cout << ans << endl;
}
