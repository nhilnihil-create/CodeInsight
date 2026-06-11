#include<bits/stdc++.h>
using namespace std ; 

int main () {
  long long N , S; 
  cin >> N ;
  S = 0 ; 
  
  for (int i = 0  ; i <= N ; i++){
    if ((i % 5) == 0 || (i % 3) == 0 || (i % 15) == 0){
      S = S  ; 
    }
    else {
      S = S + i  ; 
    }
    
  }
  cout << S << endl ; 
}
