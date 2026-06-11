#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;

int fac(int a ){
  if( a == 0 ){ return 1LL;}
  else{ return ( a*fac(a-1) )%MOD;}
}

signed main(void){
  
  int N; cin >> N;
  string S; cin >> S;
  vector<bool> vec(2*N,false);
  // false　がL、trueがRにそれぞれ対応
  
  int ans = 1LL;
  
  int left = 1; int right = 0;
  
  for(int i = 1; i < 2*N; i++){
    if( S[i-1] != S[i] ){ vec[i] = vec[i-1];}
    else{ vec[i] = !vec[i-1];}
    
    if( vec[i] ){ right++;}
    else{ left++;}
    
  }
  
  if( !vec[2*N-1] || left != right ){ cout << 0 << endl; return 0;} //このような塗り方は不可能
  if( S.front() == 'W' || S.back() == 'W' ){ cout << 0 << endl; return 0;} 
  
  int l = 0;
  
  for(int i = 0; i < 2*N; i++){
    if(!vec[i]){ l++;}
    else{ ans *= l;  l--;}
    
    ans %= MOD;
  }
  
  cout << ( ans*fac(N) )%MOD<< endl;
  
  return 0;
}