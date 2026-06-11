#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N ; 
  cin >> N ; 
  vector<int> P(N+1) ; 
  
  for(int i = 1 ; i <= N ; i++ ) {
    cin >> P.at(i) ; 
  }
  
  int min = P.at(1); 
  int cnt = 0 ; 
  
  for(int i = 1 ; i <= N ; i++){
    

    
    if(min >= P.at(i) ){
      min = P.at(i) ;
            cnt++ ; 
    }
    else{

    }
    
     //   cout << i << " " <<  min << endl ; 
  }
  cout << cnt << endl ; 
  
}