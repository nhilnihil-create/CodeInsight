#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N ; 
  cin >> N ; 
  vector<int> H(N) ; 
  int L = 0   ;
  int R = 0   ; 
  
  
  for(int i = 0 ; i < N ; i++){
    cin >> H.at(i) ;  

  }
  
  for(int i = 0 ; i < N-1 ; i++){
    if(H.at(i) >= H.at(i+1) ){
      L++ ; 

    }
    else{
      if(L >= R){
        R = L ; 
      }
      L = 0 ; 
    }
    
  }

  
  cout << max(R,L) << endl  ;
  
}