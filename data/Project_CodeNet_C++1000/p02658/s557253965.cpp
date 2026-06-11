#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MX = 1e18;

int main(){
  //整数をN個もらうが、積の合計が10^18を超えると-1を表示
  int n;
  cin >> n;
  ll ans = 1;
  bool ng = false;
  for (int i = 0; i < n;i++){
    ll a;
    cin >> a;
    if (a == 0){
      cout << 0 << endl;
      return 0;
    }
    if ( ng || (MX+1)/ans < a || ans*a > MX){
      ng = true;
    }
    ans *= a;
  }
  if (ng) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}

