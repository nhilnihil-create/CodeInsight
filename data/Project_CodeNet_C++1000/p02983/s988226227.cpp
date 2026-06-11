#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll L,R;
  cin >> L >> R;
  ll ans = 2019;
  for(int i=L;i<R && i<=L+2019;i++){
    for(int j=i+1;j<=R && j<=L+2019;j++){
      ll i0 = i%2019;
      ll j0 = j%2019;
      ll tmp = (i0*j0)%2019;
      if(ans > tmp){
        ans = tmp;
      }
    }
  }
  cout << ans << endl;
  
  return(0);
}