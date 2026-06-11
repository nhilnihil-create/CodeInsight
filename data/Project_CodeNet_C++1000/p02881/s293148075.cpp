#include<bits/stdc++.h>
using namespace std ;

int main(){
  int64_t N , cnt = 0 ; 
  cin >> N ; 
  
  int64_t T = 1e13;
  
  
  for(int64_t i = 1 ; i <= sqrt(N) ; i++ ){
      //cout << i << " " << j << endl ; 
      if( N%i == 0 ){
        int64_t j = N/i ; 
        cnt = min(T , i+j -2) ; 
      }
    
    
  }
  
  cout << cnt << endl;
  
}