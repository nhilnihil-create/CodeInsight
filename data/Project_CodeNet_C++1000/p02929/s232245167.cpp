#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

int main(){
  
  ll n; cin >> n;
  string s; cin >> s;
  
  vector<bool> side(2*n);
  
  side[0] = false;
  
  ll t = 0,f = 1;
  
  for(ll i = 1; i < 2*n; i++){ 
    
    if( s[i-1] != s[i] ){ side[i] = side[i-1]; }
    else{ side[i] = !side[i-1];}
    
    if(side[i]){ t++;} else{ f++;}
  
  }
  
  if( s[0] == 'W' || s[2*n-1] == 'W' || t != f ){ 
    cout << 0 << endl; return 0;
  }
  
  ll l = 0,r = 0; ll ans = 1LL;
  
  for(ll i = 0; i < 2*n; i++){ 
    
    if(side[i]){
      ans *= max(l-r,0LL);
      ans %= MOD;
    }
  
    if(side[i]){r++;}
    else{l++;}
    
  }
  

  
  for(ll i = 1; i <= n; i++){
    
    ans *= i;
    
    ans %= MOD;
    
  }

  cout << ans << endl;
  
  return 0;
}
    
  