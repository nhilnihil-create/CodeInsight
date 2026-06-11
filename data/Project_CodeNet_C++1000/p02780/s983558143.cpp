#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N , K ; 
  cin >> N >> K ; 
  vector<double> P(N+1) ; 
  pair<int , int > C ; 
  int T = 0 ; 
  int j = 1 ; 
  C.first = 0 ; 
  C.second = 0 ; 
  for(int i = 1 ; i <= N ; i++) {
    cin >> P.at(i) ; 
    T += P.at(i) ; 
    if(i > K ){
      T -= P.at(i - K) ; 
    }    
    if(T > C.second){
      C.second = T ; //
      C.first = i ; //K個の和が一番大きいのはi-K~iまでのK項
    }
    j++ ; 
  }
  
  //cout << C.first << " " << C.second << endl ; 
  
  double ans = 0 ; 
  
  for(int i = C.first - K +1 ; i  <=  C.first  ; i++){
    //cout << P.at(i) << endl ; 
    ans += P.at(i)*(P.at(i)+1)/(P.at(i)*2) ; 
  }
  cout << fixed << setprecision(11) << ans << endl ; 
  
}