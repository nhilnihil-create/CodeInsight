#include<bits/stdc++.h>
#define rep(i,N) for(int i = 0 ; i <(N) ; i++)
using namespace std ; 


int main() {
  int N ; 
  cin >> N ; 
  vector<int> A(N) ; 
  for(int i = 0 ; i < N ; i++){
    cin >> A.at(i) ; 
  }
  sort(A.begin(),A.end()) ; 
  reverse(A.begin(),A.end()) ; 

  int64_t cnt = 0 ; 
  int t = N-1 ; 
  rep(i , N){
    int lim = 2 ; 
    if(i==0) lim =1 ; 
    rep(j , lim){
      if(t > 0 ){
      	cnt += A.at(i) ; 
      	t-- ; 
      }
    }
  }

  
  cout << cnt << endl ; 
}