#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  ll n,a,b;
  cin >> n >> a >> b;

  ll ans;
  if ((b-a) % 2 == 0){
    ans = (b-a) / 2;
  } else {
    ll x = (b-a) / 2 + a;
    ll y = (n-(a+(n-b))+1) / 2 + (n-b);
    ans = min(x,y);
  }
  cout << ans << endl;
  
  return 0;
}
