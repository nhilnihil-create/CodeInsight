#include<bits/stdc++.h>
using namespace std ; 


int main() {
  double V , M ;
  int T , N;
  cin >> N >> M ; 
  vector<int> A(N) ;
  T = 0 ; 
  V = 0 ;
  
  for (int i = 0 ; i < N ; i++){
    cin >> A.at(i) ;
    V = V + A.at(i) ; 
  }
  
    for (int i = 0 ; i < N ; i++){
    
    if (A.at(i) >= V/(4*M)){
    	T++ ; 
    }
  }


  if (T >= M){
    cout << "Yes" << endl ; 
    return 0 ; 
  }
  
  else {
    cout << "No" << endl ;  
    return 0 ; 
  }





}
