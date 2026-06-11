#include<bits/stdc++.h>
using namespace std ; 

int main () {
  int n ; 
  cin >> n ;
  string S ; 
  cin >> S;
  int64_t cnt = 0 ; 
  vector<int64_t> A(3) ; 
  
  for(int i = 0 ; i < n ; i++){
    if(S.at(i) == 'R') A.at(0)++ ; 
    if(S.at(i) == 'G') A.at(1)++ ; 
    if(S.at(i) == 'B') A.at(2)++ ;     
  }

  int64_t max_n ; 
  max_n = A.at(0)*A.at(1)*A.at(2) ; 
  
  for(int i = 0 ; i < n-2 ; i++){
    for(int j = i+1 ; j < n-1 ; j++){
      int k  = 2*j - i  ;
      if( k < n ) {
        if ( S.at(i) != S.at(j) && S.at(i) != S.at(k) && S.at(j) != S.at(k) ) cnt++ ; 
      }
    }
  }
  cout << max_n - cnt << endl ; 
}
