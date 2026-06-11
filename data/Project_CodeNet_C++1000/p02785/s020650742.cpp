#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int64_t N, K ; 
  cin >> N >> K ; 
  vector<int64_t> H(N) ; 
  int64_t cnt = 0 ; 
  
  for(int i = 0 ; i < N ; i++){
    cin >> H.at(i) ; 
  }
  sort(H.begin() , H.end()) ; 
  reverse(H.begin() , H.end()) ; 
  
  for(int i = K ; i < N ; i++ ){
    cnt = cnt + H.at(i) ; 
  }
  
  cout << cnt << endl ; 
}

