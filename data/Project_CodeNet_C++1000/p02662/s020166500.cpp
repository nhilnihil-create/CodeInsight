#include <bits/stdc++.h>
using namespace std; 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define rep(i,a,b) for(int i=a;i<b;i++)
#define reprev(i,a,b) for(int i=b-1;i>=a;i--)
#define all(c) c.begin(),c.end()
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vin(a,n) vi a(n); rep(i,0,n) cin>>a[i];
#define vout(a) rep(i,0,a.size()) cout<<a[i]<<" "; cout<<endl;
#define mapp map<int,int>
#define pb push_back
#define mp  make_pair
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX
#define pi 3.1415926535897932384626
#define tr(container, it) \
for(auto it = container.begin(); it != container.end(); it++)

bool comps(const pair<int,int> &a, const pair<int,int> &b) {return (a.second<b.second);} 

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
    IOS
    int n,s;
    cin>>n>>s;
    vin(a,n);
    vector<vi> dp(n+1, vi(s+1));
    dp[0][0]=power(2,n,mod2);
    rep(i,0,n)
    {
        rep(j,0,s+1)
        {
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=mod2;
            if(j+a[i]<=s)
            {
                dp[i+1][j+a[i]] += (dp[i][j])*(power(2,mod2-2,mod2));
                dp[i+1][j+a[i]]%=mod2;
            }
        }
    }
    cout<<dp[n][s];
    return 0;
}
