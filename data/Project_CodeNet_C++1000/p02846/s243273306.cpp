#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long mod = 1000000007;
const int INF = 1001001001;

int main(){
  ll t1,t2,a1,a2,b1,b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if(a1*t1 + a2*t2 > b1*t1 + b2*t2){
    swap(a1,b1);
    swap(a2,b2);
  }else if(a1*t1 + a2*t2 == b1*t1 + b2*t2){
    cout << "infinity" << endl;
    return 0;
  }
  ll ans ;
  if(a1 < b1){
    cout << 0 << endl;
    return 0;
  }else{
    ll one_period = (b1*t1 + b2*t2) - (a1*t1 + a2*t2);
    ll half_period = a1*t1 - b1*t1;
    if(half_period % one_period ==0){
      ans = (half_period / one_period) * 2;
    }else{
      ans = (half_period / one_period) *2 + 1;
    }
    cout << ans << endl;     
  }
}