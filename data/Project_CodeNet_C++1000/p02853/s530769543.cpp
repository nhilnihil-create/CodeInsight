#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v) do { x = max(x, v); } while(0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  ll x,y;
  cin>>x>>y;
  map<ll,ll> mp ={{1, 300000}, {2, 200000}, {3, 100000}};
  ll ans = mp[x] + mp[y];
  if (x==1 && y==1)
    ans += 400000;
  cout<<ans<<endl;
  return 0;
}
