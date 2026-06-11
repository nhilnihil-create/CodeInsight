#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MOD 1000000007
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);}
ll int power(ll int x, ll int y, ll int p)  
{  
   ll int res = 1;     // Initialize result  
 
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
ll int dp[2005];
ll int solve(ll int n)
{
  if(n<0)
    return 0ll;
  if(n==0)
    return 1;
  if(dp[n]!=-1)
    return dp[n];
  ll int ans=0;ll int i;
  for(i=3;i<=n;i++)
    {ans+=solve(n-i);ans%=MOD;}
  dp[n]=ans;
  return ans;
}
int main()
{
   ll int T;
T=1;


    while(T--)
    {
      ll int n;
      cin>>n;
       int i;
      vector< int>v1,v2;
      //map<ll int,ll int> mx,mn;

      for(i=0;i<n;i++)
      {
        ll int p,q;
        cin>>p>>q;
        v1.push_back(p);
        v2.push_back(q);

      }
      int m1=INT_MIN;
        int m3=INT_MIN;
        int m5=INT_MIN;
        int m7=INT_MIN;
        int m2=INT_MAX;
        int m4=INT_MAX;
        int m6=INT_MAX;
        int m8=INT_MAX;
       // ll int i;
        for(int i=0;i<v1.size();i++){
            m1=max(m1,v1[i]+v2[i]);
            m2=min(m2,v1[i]+v2[i]);
            m3=max(m3,v1[i]-v2[i]);
            m4=min(m4,v1[i]-v2[i]);
            m5=max(m5,v1[i]+v2[i]);
            m6=min(m6,v1[i]+v2[i]);
            m7=max(m7,v1[i]-v2[i]);
            m8=min(m8,v1[i]-v2[i]);
        }
        
        int val1=m1-m2;
        int val2=m3-m4;
        int val3=m5-m6;
        int val4=m7-m8;
        ll int ans= max(max(val1,val2),max(val3,val4));
        cout<<ans<<endl;
     
    }

    return 0;
       }