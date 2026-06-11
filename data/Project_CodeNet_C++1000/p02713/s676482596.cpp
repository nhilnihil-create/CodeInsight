#include<bits/stdc++.h>
using namespace std ; 

int main () {
  int K ; 
  cin >> K ; 
  
  int64_t T = 0 ; 
  
  for(int i = 1 ; i <= K ; i++){
    for(int j = 1 ; j <= K ; j++){
      for(int k = 1 ; k <= K ; k++ ){
        T += gcd(gcd(i , j ) , k ) ; 
      }
    }
  }
  cout << T << endl ; 

}