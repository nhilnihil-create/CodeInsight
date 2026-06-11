#include<bits/stdc++.h>
using namespace std ; 


int main(){
  int N ; 
  cin >> N ; 
  vector<int> B(N+1) ; 
  int cnt = 0 ; 
  
  for(int i = 1 ; i <= N-1 ; i++){
    cin >> B.at(i) ;
  }
  
  B.at(0) = 10e6 ; 
  B.at(N) = 10e6 ; 
  
  for(int i = 0 ; i < N ; i++){
    //cout << B.at(i)  << " " << B.at(i+1) << endl ; 
    if(B.at(i) <= B.at(i+1)){
      cnt += B.at(i) ;
    }
    else{
      cnt += B.at(i+1) ; 
    }
  }

  cout << cnt << endl ; 
 
}