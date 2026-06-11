#include <bits/stdc++.h>
using namespace std;
int main(){
  int64_t T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  bool same = false;
  if(T1*A1 + T2*A2 < T1*B1 + T2*B2){
    swap(A1,B1);
    swap(A2,B2);
  }
  if(T1*A1 + T2*A2 == T1*B1 + T2*B2){
    same = true;
  }
  
  if(same){
    cout << "infinity" << endl;
  }
  else{
    int64_t ans = 0;
    if(A1 < B1){
      int64_t sub = T1*A1 + T2*A2 - (T1*B1 + T2*B2);
      int64_t one = T1*B1 - T1*A1;
      //cout << sub << " " << one << endl;
      ans = 1;
      ans += (one/sub)*2;
      if(one %sub == 0){
        ans--;
      }
    }
    cout << ans << endl;
  }
}