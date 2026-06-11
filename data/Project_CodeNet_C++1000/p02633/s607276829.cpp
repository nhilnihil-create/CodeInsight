#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < (int)(n); i++)

int main(){
  int X;
  cin >> X;
  int ans = 1;
  int Y = X;
  
  while(Y%360 != 0){
   Y = (Y+X) % 360;
    ans++;
  }
  cout << ans << endl;
}
