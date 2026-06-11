// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

const ll MOD = 1000000007;
int main() {
  int n, k; cin >> n >> k;
  ll ans = 0;
  vector<ll> acc(n+2, 0);
  loop(i,0,n+1) acc[i+1] = acc[i] + i;
  
  loop(i,k,n+2) {
    ll min_ = acc[i];
    ll max_ = (acc[n+1] - acc[n-i+1]);
    ans += max_ - min_ + 1;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
