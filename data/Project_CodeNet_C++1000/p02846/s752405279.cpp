#include <bits/stdc++.h>
using namespace std;

int main(){
  long long T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  long long v1 = A1-B1, v2 = A2-B2;
  long long ans;
  if(v1 > 0 && v2 > 0) ans = 0;
  else if(v1 < 0 && v2 < 0) ans = 0;
  else if(v1*T1 == -v2*T2) ans = -1;
  else{
    if(v1 < 0) v1 *= -1, v2 *= -1;
    if(v1*T1 > -v2*T2) ans = 0;
    else{
      long long posFirst = v1*T1;
      long long dif = v1*T1 + v2*T2;
      if(dif < 0) dif *= -1;
      ans = posFirst/dif*2 + 1;
      if(posFirst % dif == 0) ans -= 1;
    }
  }
  if(ans == -1) cout << "infinity" << endl;
  else cout << ans << endl;
}
