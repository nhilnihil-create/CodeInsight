#include<bits/stdc++.h>
using namespace std;

int main(){
  double W,H,X,Y;
  cin >> W >> H >> X >> Y;
  bool si=(2*X==W&&2*Y==H);
  double ans=W*H/2;
  cout << ans << " " << (si?1:0) << endl;
  return 0;
}