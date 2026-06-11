#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  ll x = n/(a+b);
  ll y = n%(a+b);
  ll ab = min(y,a);
  ll ans = x*a+ab;
  cout << ans << endl;
  return 0;
}
