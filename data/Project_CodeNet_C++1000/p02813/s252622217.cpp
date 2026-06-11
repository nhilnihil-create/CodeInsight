#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  vector<int> P(N) , Q(N) ,A(N); 
  int a = 0  , b = 0  ; 
  int cnt = 1 ; 
  
  
  for(int i = 0 ; i < N ; i++){
    cin >> P.at(i) ; 
    A.at(i) = i+1 ; 
  }
  
  for(int i = 0 ; i < N ; i++){
    cin >> Q.at(i) ; 
  }

  
  do{
      int  cnt1 = 0 , cnt2 = 0  ;
      for(int j = 0 ; j < N ; j++){
        if(A.at(j) == P.at(j)){
         cnt1++ ; 
        }
      }
      if(cnt1 == N){
        a = cnt ; 

      }
      
      for(int j = 0 ; j < N ; j++){
        if(A.at(j) == Q.at(j)){
          cnt2++ ; 
        }
      }  
      if(cnt2 == N){
         b = cnt ;  
      }      
    
    cnt++ ; 

  }while (next_permutation( A.begin() , A.end() ) );

    cout << abs(a - b ) << endl ; 
}