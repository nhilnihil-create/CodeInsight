#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N ; 
  string S ; 
  int T = 0 ; 
  
  cin >> N ; 
  cin >> S ; 
  
  for (int i = 0 ; i < S.size()-2 ; i++){
    if(S.at(i) == 'A' && S.at(i+1) == 'B' && S.at(i+2) == 'C' ){
      T++ ;
    }
  }
  
  
  cout << T << endl ; 
  
}
