#include<bits/stdc++.h>
using namespace std ;

int main(){
  int64_t n ; 
  cin >> n ; 
  
  
  ///////////////////////素因数分解
  vector<pair<int64_t , int>> fs ; 
  for(int64_t i = 2 ; i*i <= n ; i++){
    int x = 0 ; 
    while(n%i == 0 ){
      n /= i ; 
      x++ ;
    }
    fs.emplace_back(i,x) ;    
  }
  if( n != 1)  fs.emplace_back(n,1) ; 
  
  //////////////////
  int ans = 0 ; 
  
  for(auto p : fs){
    int x = p.second ; 
    int b = 1 ; 
    while ( b <= x){
      x -= b ; 
      b++ ; 
      ans++ ; 
    }
  }
  
  cout << ans << endl ; 
  
  
}