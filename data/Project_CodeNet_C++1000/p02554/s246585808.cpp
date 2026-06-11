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
unsigned long long power(unsigned long long x,
                        int y, int p)
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


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int t=1;
	//cin>>t;
	while(t--){
	    
	    ll ans=0;
	    cin>>n;
	    if(n<2){
	        ans=0;
	    }
	    else
	    {
	        ans=(power(10,n,mod) - 2*power(9,n,mod)+ power(8,n,mod)+ 2*mod)%mod;
	    }
	   
	    cout<<ans<<"\n";
	    
	    
	}
	return 0;
}
