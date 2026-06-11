#include<bits/stdc++.h>
using namespace std ;
const int A_MAX = 1000005 ; 

int main() {
  int N ; 
  cin >> N ; 
  vector<int> A(A_MAX+1) ;
  vector<int> C(A_MAX+1), cnt(A_MAX+1); 
  
  for(int i = 1 ; i <= N ; i++) {
    cin >> A.at(i) ; 
    C.at(A.at(i))++ ; //Cは要素の分布 
  }
  
  int ans = 0 ; 

  for(int i = 1 ; i <= A_MAX ; i++){
    for(int j = i ; j <= A_MAX ; j += i ){
      cnt.at(j) += C.at(i)   ;//cntは　
    }
  }
  
  for(int i = 1 ; i <= A_MAX ; i++ ){
    if(cnt.at(i) == 1 && C.at(i) ){
      ans += C.at(i) ; 
    }
  }
  
  cout << ans << endl ; 
  
}