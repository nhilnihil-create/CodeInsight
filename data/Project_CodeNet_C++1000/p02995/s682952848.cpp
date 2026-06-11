#include<bits/stdc++.h>
using namespace std ; 
#define rep(i,N) for(int i = 0 ; i <(N) ; i++)
typedef long long ll;


ll f(ll x , ll C , ll D){
  ll res = x ; 
  res -= x/C ; 
  res -= x/D ; 
  res += x/lcm(C,D) ; 
  return res ; 
}


int main(){
  ll A , B  ; 
  ll C , D ; 
  cin >> A >> B >> C >> D ; 
  
  ll ans = f(B, C ,D) - f(A-1,C,D) ; 
  cout << ans << endl ; 
  return 0 ; 
  
}