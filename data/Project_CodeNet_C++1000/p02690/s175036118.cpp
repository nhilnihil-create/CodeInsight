#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ;
  cin >> N ; 
  
  for(int a = 1 ; a < 230 ; a++){
    int64_t a5 = 1; 
    for(int i = 0 ; i < 5 ; i++) a5 *= a ; 
    
    for(int b = -230 ; b < 230 ; b++){
      int64_t b5 = 1 ; 
      for(int i = 0 ; i < 5 ; i++) b5 *= b ; 
      
      if(a5 - b5 == N) {
        cout << a << " "<< b << endl  ;
        return 0 ; 
      }
    }
  }
    
    
}