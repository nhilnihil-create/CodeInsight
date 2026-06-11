#include <bits/stdc++.h>
using namespace std;

int main() { 
  int A,B;
  cin >> A >> B;
  
  int ans = -1;
  for(int i=1; i<1010; i++){
    if( 12.5*A <= i && i<12.5*(A+1) && 10*B<= i && i<10*(B+1) ){
      ans = i;
      break;
    }
  }
  
  cout << ans << endl;
}