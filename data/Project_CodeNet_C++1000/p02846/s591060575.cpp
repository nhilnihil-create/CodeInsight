#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int t1, t2;
  ll a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  ll ab1 = (a1 - b1)*t1;
  ll ab2 = (a2 - b2)*t2;
  if(ab1+ab2 == 0){
    cout << "infinity" << endl;
    return 0;
  }
  if((ab1>0 && ab1+ab2>0) || (ab1<0 && ab1+ab2<0)){
    cout << 0 << endl;
    return 0;
  }
  ll ans = abs(ab1) / abs(ab1+ab2) *2 +1;
  if(abs(ab1) % abs(ab1+ab2) ==0) --ans;
  cout << ans << endl;
}