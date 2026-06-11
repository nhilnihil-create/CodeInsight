#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 
 int mod=1000000007;
 long long fast_exp(long long a,long long n,long long mod1)
    {
     
      if (n==0)return 1;
      else if (n==1)return a;
      if (n%2==0)return fast_exp((a*a)%mod1,n/2,mod1);
      else return (a*fast_exp((a*a)%mod1,n/2,mod1))%mod1;
    }
void solve()
{
    long long n,k;
    cin >> n >> k;
    long long dp[100001];
    for (int c=k;c>=1;c--)
        {
        long long  total=fast_exp(k/c,n,mod);
            for (int c1=2*c;c1<=k;c1+=c)
                total=(total-dp[c1]+mod)%mod;
            dp[c]=total;
        }
        long long total=0; 
        for (int c=1;c<=k;c++)
            (total+=1LL*c*dp[c])%=mod;
        cout << total << endl;

        

}
    


    
 

int main()
{
    fast_io;
    int t;
   // cin >> t;
t=1;
    for (int tt=1;tt<=t;tt++)
    {
       // cout << "Case #" << tt << ": " ;    
        solve();
        
 
    }
 
    
    return 0;
}
 
