#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  if ( b==1){
    cout << 0 << endl;
  return 0 ;
  }
  int sum=a ;
    int ans = 1 ;
  for ( ; ; ans++){
    if (sum < b){
      sum+= a-1 ;
    }else break;
   }
  cout << ans << endl;
}