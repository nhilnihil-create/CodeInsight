#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,Y;
  cin >> X >> Y;
  string ans = "No";
  for (int i=0;i<=Y/2;i++){
    if( 2*i + 4*(X-i) == Y) ans = "Yes";
//    cout << i << endl;
  }
  cout << ans << endl;
  
  
  return 0;
}