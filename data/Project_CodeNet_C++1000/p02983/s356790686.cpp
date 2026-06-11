#include<bits/stdc++.h>
using namespace std ; 
#define rep(i,N) for(int i = 0 ; i < (N) ; i++ )

int main() {
  int64_t L , R ; 
  cin >> L >> R ; 
  
  R = min(R , L+2019) ; 
  int ans = 2018 ; 
  for(int64_t i = L ; i <= R ; i++){
    for( int64_t j = i+1 ; j <=R ; j++ ){
      int x = (i*j)%2019 ; 
      ans = min(ans , x) ; 
    }
  }
  
  cout << ans << endl ; 

  return 0 ; 
}