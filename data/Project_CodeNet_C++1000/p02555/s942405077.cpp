#include  <bits/stdc++.h>
using namespace std; 

#define ll long long 

const ll mod = 1e9 +7 ; 

int main(){
      
     ll s ; 
     cin >> s; 
     
     if (s < 3 ) {
           
           cout << "0" ; 
           return 0 ; 
     }
     
     if (s == 3 ) {
          
           cout << "1" ; 
           
           return 0 ; 
     }
     
     ll dp[2001] ; 
     
     dp[0] = 0 ; 
     dp[1] = 0 ;
     dp[2] = 0 ; 
     dp[3] = 1 ; 
     
     for(ll i = 4 ; i <= s ; i ++ ) {
            
            ll state = 0 ; 
            
            for(ll j = 3 ; j <= i ; j ++ ){
                  
                   state += ((dp[i - j])%mod) ; 
            }
            
            dp [i] = (state + 1)%mod ; 
     }
     
     cout << dp[s]%mod << "\n";  
     
     
     
     
}