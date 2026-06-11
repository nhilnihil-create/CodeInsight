#include<bits/stdc++.h>
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define repn(i,a,b)   for(int i=a;i>=b;i--)
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define mp  make_pair
#define all(v) (v).begin(), (v).end()
#define mod 998244353
#define inf 1e18 
 
using namespace std;

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
int modp(int a,int m,int n)
{
    n=n%(m-1);
    a=a%m;
    int res=1;
    while(n>0)
    {
        if(n&1) res=(res*a)%m;
        a=(a*a)%m;
        n>>=1;
    }
    return res;
}

int modInverse(int n, int p) 
{ 
    return modp(n, p, p-2); 
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    
    IOS;
    int n,s,i,j;
    cin>>n>>s;
    vi v(n);
    for(i=0;i<n;i++) cin>>v[i];
    vi dp(s+1);
    dp[0]=power(2,n,mod);
    for(i=0;i<n;i++)
    {
        for(j=s;j>=v[i];j--)
        {
            dp[j]+=(dp[j-v[i]]*modInverse(2,mod))%mod;
            dp[j]%=mod;
        }
    }
    // for(i=0;i<=s;i++) cout<<dp[i]<<endl;
    cout<<dp[s];
}