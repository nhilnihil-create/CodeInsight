/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
#define int long long
int power(int x, int y, int p) 
{ 
    int res = 1;      // Initialize result 
  
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
  
// Returns n^(-1) mod p 
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
int nCrModPFermat(int n, int r, int p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    int fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 
  
int32_t main()
{
  
  int n,i,j,k=1e9+7,l;
  int x,y;
  cin>>x>>y;
  int x1,x2;bool hi=true;
  if((2*y-x)>=0&&(2*y-x)%3==0)
  {
    if((2*x-y)>=0&&(2*x-y)%3==0)
    {
      x1=(2*y-x)/3;x2=(2*x-y)/3;
    }
    else
     hi=false;
  }
  else
   hi=false;
   if(hi)
   {
    l=nCrModPFermat(x1+x2,x1,k);
    cout<<l;
   }
   else
    cout<<"0";
    return 0;
}
