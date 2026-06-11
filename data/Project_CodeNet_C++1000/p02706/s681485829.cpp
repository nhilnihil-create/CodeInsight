#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N , M ;
 
  int T= 0  ; 
  
  cin >> N >> M ; 
  vector<int> A(M) ;
  
  for (int i = 0 ; i < M ; i++){
    cin >> A.at(i) ; 
    T = T + A.at(i) ; 
  }

  
  if( N < T){
    cout << "-1" << endl ; 
  }
  else {
    cout << N - T << endl ;
  }
}