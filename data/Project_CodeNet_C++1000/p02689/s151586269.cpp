#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N , M ; 
  cin >> N >> M ;
  vector<int> H(N) ;
  vector<int> A(M) ; 
  vector<int> B(M) , count(N) ; 
  int T = 0 ; 
  
  for(int i  = 0 ; i < N ; i++){
    cin >> H.at(i) ;
    count.at(i) = 0 ;
  }
  
  for(int i = 0 ; i < M ; i++){
    cin >> A.at(i) >> B.at(i) ; 
  }
  
  for(int i = 0 ; i < M; i++){
    if( H.at(A.at(i)-1) > H.at(B.at(i)-1) ){
      count.at(B.at(i)-1)++ ; 
    }
    else if(H.at(A.at(i)-1) == H.at(B.at(i)-1)){
      count.at(B.at(i)-1)++ ;
      count.at(A.at(i)-1)++ ;
    }
    else{
      count.at(A.at(i)-1)++ ; 
    }
  }
  
  for(int i = 0 ; i < N ; i++){
    if(count.at(i)==0)  T++ ; 
  }
  cout << T << endl ; 
}