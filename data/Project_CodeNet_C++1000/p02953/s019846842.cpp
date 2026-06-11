#include<bits/stdc++.h>
using namespace std ;

int main(){
  int64_t N ; 
  cin >> N ; 
  vector<int64_t> H(N) ;
  
  for(int i = 0 ; i < N ; i++){
    cin >> H.at(i) ; 
  }
  int64_t max_cnt = H.at(0) ;  ; 
  
  for(int i = 1 ; i < N ; i++){
    //cout << max_cnt << endl ;         
    if( H.at(i) >= max_cnt - 1){
      H.at(i) = H.at(i)  ; 
    }
    else if(H.at(i) < max_cnt ){
      cout << "No" <<endl ;
      return 0 ; 
    }

    
    max_cnt = max(max_cnt,H.at(i)) ; 
    
  }
  

  
  cout << "Yes" << endl ;
}