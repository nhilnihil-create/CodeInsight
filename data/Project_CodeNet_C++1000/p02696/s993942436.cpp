#include<bits/stdc++.h>
using namespace std ;

int main(){
  int64_t a , b , n ; 
  cin >> a >> b >> n ; 
  int64_t x = n;
  
  if(n >= b-1) x = b-1 ; 
  int64_t ans = a*x/b - a*(x/b) ; 
  
  cout << ans << endl ; 
  return 0 ; 
  
}