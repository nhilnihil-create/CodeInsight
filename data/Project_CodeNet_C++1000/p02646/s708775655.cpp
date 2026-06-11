#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t A,V,B,W,T;
  cin >> A >> V >> B >> W >> T;
  if(V*T>=(abs(B-A)+W*T)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
