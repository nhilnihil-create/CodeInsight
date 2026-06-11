#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define all(a) a.begin(),a.end()
#define pb push_back
#define f(i,l,u) for(ll i=l;i<u;i++)
#define lb lower_bound
#define ub upper_bound
#define pii pair<ll,ll> 

        
long long power( long long x, 
                         ll y, ll p) 
{ 
   long long res = 1; // Initialize result 
  
    x = x % p; 
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 

  
int main() {
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
   
  ll n;
  cin>>n;
  
  ll mod=1e9+7;
ll dp[2001]={0};
dp[0]=1;
dp[1]=0;
dp[2]=0;
f(i,3,2001)
{
    dp[i]+=dp[i-1];
    dp[i]%=mod;
    if(i-3>=0)
    dp[i]+=dp[i-3];
    dp[i]%=mod;
    
}
cout<<dp[n]<<endl;
   

      

return 0;    
}