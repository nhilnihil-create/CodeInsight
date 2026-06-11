#include <bits/stdc++.h>
using namespace std;

int main() {
  //位置A,B;
  //速さV,W;
  //時間T；
  double A,V,B,W,T;
  cin >> A >> V >> B >> W >> T;
  double X = (abs(A-B) / (V-W));
  if(X <= T && X > 0){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}
