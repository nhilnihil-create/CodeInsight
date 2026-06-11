#include<bits/stdc++.h>
using namespace std ; 

int main() {
  string S ; 
  cin >> S ; 
  int N ; 
  N = S.size() ; 

  
  for(int i = 0 ; i < N ; i++){
    
    
    if( (i+1) % 2 == 0 ){ //偶数
      if( (S.at(i) != 'L') &&  (S.at(i) != 'U' ) && (S.at(i) != 'D')  ){
        cout << "No" << endl ; 
        return 0 ; 
      }
    }
    
    else if( (i+1)  % 2 == 1){ // 奇数
      if( (S.at(i) != 'R') && (S.at(i) !='U') && (S.at(i) !='D')  ){
        cout << "No" << endl ; 
        return 0 ; 
      }      
    }

    
  }
  
  cout << "Yes" << endl ;

  
}