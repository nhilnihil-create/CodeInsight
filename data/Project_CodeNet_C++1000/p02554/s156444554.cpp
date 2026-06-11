#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int mod = 1e9+7;
lli power(lli x, lli  y,lli p)  
{  
    lli res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  
int main() {
 //   cout<<"Hello World!";
    int n;
    cin>>n;
    lli ans = power(10,n,mod);
    ans%=mod;
    ans-=power(9,n,mod);
    if(ans<0)
    ans+=mod;
    ans%=mod;

    ans-=power(9,n,mod);
    if(ans<0)
    ans+=mod;
    ans%=mod;
    ans+=power(8,n,mod);
    ans%=mod;
    cout<<ans<<endl;
}
