#include<bits/stdc++.h>
using namespace std ; 


int main() {
  int N ;
  cin >> N ; 
  vector<int> A(N) ; 
  map<int, int> P ;
  
  
  for(int i = 0 ; i < N ; i++){
    cin >> A.at(i) ; 
    P[A.at(i)] = i   ;
  }

  
  for(int i = 1 ; i <= N ; i++ ){
    cout << P.at(i)+1 << " " ; 
  }

}