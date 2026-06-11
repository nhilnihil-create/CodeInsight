#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
const ll N_MAX = 2e5 + 5 ; 

int count(ll x){
  ll y  =  ( x*(x-1) )/2 ;
  return y ; 
}

int main(){
  ll N ;
  cin >> N ; 
  vector<int> A(N) ; 
  vector<ll> C(N_MAX) ; //同じA_iの値が何個あるか？
  
  for(int i = 0 ; i < N_MAX ; i++) C.at(i) = 0 ; 

  for(int i = 0 ; i < N ; i++){
    cin >> A.at(i) ; 
    C.at(A.at(i))++ ; 
  }

 
  ll MAX_ANS = 0  ; 

  for(int j = 1 ; j < N_MAX ; j++){
    ll ANS = 0 ; 
    if(C.at(j) > 0){
      ANS = C.at(j)*(C.at(j)-1)/2 ; 
      MAX_ANS += ANS ;  
      
      //cout << MAX_ANS << endl ; 
    }
  }
  
  
  for(int i = 0  ; i < N ; i++){
    
    C.at(A.at(i))-- ;     
    ll ans = 0 ; 
    ll T = 0 ; 
    
    ans = C.at(A.at(i)) ; 
    T += count(ans+1);
    T -= count(ans) ; 
    
    cout << MAX_ANS - T << endl ; 
    
    C.at(A.at(i))++ ;     
  }

}