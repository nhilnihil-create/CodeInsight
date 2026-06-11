#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007

int power(int x, unsigned int y, int p)
{
    int res = 1;     // Initialize result

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

signed main()
{
   int n;
   cin>>n;
   if(n<2) cout<<0<<endl;
   else if(n==2) cout<<2<<endl;
   else
   {
       int a = power(9,n,mod);
       int b = power(9,n,mod);
       int c = power(8,n,mod);

       int res = (a+b)%mod;
       res = (res-c+mod)%mod;
       res = (power(10,n,mod) - res + mod)%mod;
       cout<<res<<endl;
   }
}
