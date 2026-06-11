#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll x,ll y,ll p)  
{  
    ll res = 1;     // Initialize result  
    if(y == 0)
        return(1 % p);
    
    x = x % p; // Update x if it is more than or  
                // equal to p 
    if (x == 0)
        return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {   
        // If y is odd, multiply x with result  
        if (y & 1LL)  
            res = (res * x) % p;  
  
        // y must be even now  
        y = y >> 1LL; // y = y/2  
        x = (x * x) % p;  
    }
    
    return res;  
}

ll solve(ll N) //N is of order 1e5
{
    ll c = 1;
    while(N)
    {
        ll set = __builtin_popcount(N);
        N = N % set;
        c++;
    }
    
    return(c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll T = 1;
    while(T--)
    {
        ll L,R,D; cin>>L>>R>>D;
        ll ans = 0;
        for(ll i=L;i<=R;++i)
        {
            if(i%D == 0)
                ans++;
        }
        
        cout<<ans<<endl;
    }
}