#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  ll n, k;
  cin >> n >> k;
  if(n % k == 0) cout << 0 << endl;
  else{
    ll ans = n;
    while(ans > abs(ans - k)){
      if(ans > k) ans %= k;
      else ans = k % ans;
    }
    cout << ans << endl;
  }
  return 0;
}