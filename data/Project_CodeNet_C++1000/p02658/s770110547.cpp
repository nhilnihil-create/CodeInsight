#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

const ll MX = 1e18;
 
int main(){
  int n;
  cin >> n;
  ll ans = 1;
  bool x = false;
 
  rep(i, n){
    ll a;
    cin >> a;
    
    if(a == 0){
      cout << 0 << endl;
      return 0;
    }
    if(x || MX / ans < a){
      x = true;
    }
    ans *= a;
  }
  if(x) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}