#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {

  // cin.tie(0);
  // ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  LL T1,T2,A1,A2,B1,B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  LL D1 = A1-B1, D2 = A2-B2;
  if(D1 > 0){
    D1 = -D1;
    D2 = -D2;
  }

  LL X = T1*D1, Y = T2*D2;

  if(D2 < 0){
    cout << 0 << endl;
  }else if(-X == Y){
    cout <<"infinity" << endl;
  }else if(X+Y < 0){
    cout << 0 << endl;
  }else{
    LL res = (-X)/(X+Y)*2 + (((-X)%(X+Y)==0)?0:1);
    cout << res << endl;
  }

  return 0;
}
