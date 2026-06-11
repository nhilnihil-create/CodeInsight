#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N , K , Q ; 
  cin >> N >> K >> Q ; 
  vector<int> A(Q) ;
  vector<int> T(N) ;
  
  for(int i = 0 ; i < N ; i++){
    T.at(i) = 0 ; 
  }
  
  for(int i = 0 ; i < Q ;i++ ){
    cin >> A.at(i) ; 
    T.at( A.at(i)- 1)++ ; 
  }
  
  for(int i = 0 ; i < N ; i++){
    if(K - Q + T.at(i) > 0 ){
      cout << "Yes" << endl ; 
    }
    else{
      cout << "No" << endl ; 
    }

  }
}