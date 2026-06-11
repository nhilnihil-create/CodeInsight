#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

  ll p = (b1 - a1) * t1, q = (b2 - a2) * t2;

  if(p + q == 0){
    cout << "infinity" << endl;
    return 0;
  }
  ll shift = p + q;
  if((p > 0 && shift < 0) || (p < 0 && shift > 0)){
    ll k = p / shift;
    k = abs(k);
    ll ans = 2 * k + 1;
    if(abs(k * shift) == abs(p)) ans--;
    cout << ans << endl;
  }else{
    cout << 0 << endl;
  }
}
