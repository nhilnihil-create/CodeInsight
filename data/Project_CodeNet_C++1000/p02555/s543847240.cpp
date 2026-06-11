#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define fill(a,b) memset(a,b,sizeof(a))

#define f first
#define s second
#define pb push_back

#define inf 1e17
#define ninf -1*1e17
#define mod 1000000007
#define N 500005
#define Ns 5005

string s;
ll n,m,o,x,y,z,d,k,l,r;
unsigned long long power(unsigned long long x, int y, int p)
{
   unsigned long long res = 1; // Initialize result
    x = x % p; // Update x if it is more than or
   // equal to p
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
unsigned long long modInverse(unsigned long long n, int p)
{
   return power(n, p - 2, p);
}
ll ncr(ll n,ll r){
   if(n<r)
   return 0;
   if(n==r)
   return 1;
   ll ans=1;
  
   for(ll i=n;i>n-r;i--){
       ans=(ans*i)%mod;
   }
   for(ll i=2;i<=r;i++){
       //ans=(ans/i);
       ans=(ans*modInverse(i,mod))%mod;
   }
   return ans;
}




int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int t=1;
	//cin>>t;
	while(t--){
	    
	    ll ans=0;
	    cin>>n;
	    for(int r=1;r<n;r++){
	        int total=n-2*r;
	        if(total<0){
	            break;
	        }
	        ans=(ans+ncr(total-1,r-1))%mod;
	    }
	   
	    cout<<ans<<"\n";
	    
	    
	}
	return 0;
}
