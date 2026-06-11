#include<bits/stdc++.h>
using namespace std ; 


int main(){
  int N ;
  cin >> N ; 
  vector<int> d(N) ; 
  int cnt = 0 ; 
  
  for ( int i = 0 ; i < N ; i++){
    cin >> d[i] ; 
  }
  
  for(int i = 0 ; i < N ; i++){
    for(int j = i+1 ; j < N ; j++){
      cnt = cnt + d[i]*d[j] ; 
    }
  }
  cout << cnt << endl ; 
  
}