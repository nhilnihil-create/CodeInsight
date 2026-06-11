#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define mod 1000000007
using namespace std;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
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
  
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 

ll nCrModPFermat(ll n, ll r, ll p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    ll x,y;
    cin >> x >> y;
    if ((x+y)%3==0)
    {
        ll n=((2*y)-x)/3;
        ll m=((2*x)-y)/3;

        if (n<0 || m<0)
        {
            cout << "0" << endl;
        }
        else
        {
            // calc and prll (n+m)Cn
            cout << nCrModPFermat(n+m,n,mod) << endl;

        }
    }
    else
    {
        cout << "0" << endl;
    }

    return 0;
}