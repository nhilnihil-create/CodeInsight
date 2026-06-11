#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  int64_t cnt = 0 ; 
  
  for( int i = 1 ; i < N ; i++){
    cnt += i ;
  }
  cout << cnt << endl ; 
  
}
