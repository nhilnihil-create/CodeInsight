#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N ; cin >> N ; 
  vector<int64_t> A(N+1) ; 

  int64_t ans = 0 ; 
  for(int i = 1 ; i <= N ; i++){
    
    for(int j = i ; j <= N ; j += i ){
      A.at(j)++ ; 

    }
    //cout << i <<" "  << cnt << endl ; 
  }
  for(int i = 1 ; i <= N ; i++){
    ans += i*A.at(i) ; 
  }
  
  cout << ans << endl ; 

  
}