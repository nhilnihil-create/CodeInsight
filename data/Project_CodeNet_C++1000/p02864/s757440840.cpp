#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 100000000000000


using namespace std;


int main()
{
   FAST/**/
   
   ll n,k;
   cin>>n>>k;
   
   if(k == n)
   {
       cout<<0;
       return 0;
   }
   
   ll arr[n];
   for(ll i=0;i<n;i++)
        cin>>arr[i];
   
   ll dp[n][k+1];
   for(ll i=0;i<n;i++)
        for(ll j=0;j<k+1;j++)
            dp[i][j] = INF;
   
   dp[0][0] = arr[0];
   
   for(ll i=1;i<n;i++)
   {
       if(i<=k)
            dp[i][i] = arr[i];
       for(ll j=i-1;j>-1;j--)
       {
           ll ct = i-1-j;
           for(ll k1=0;k1<=k;k1++)
           {
               if(k1+ct>k)
                    continue;
               ll temp = dp[j][k1];
               if(arr[i]>arr[j])
                    temp+=arr[i]-arr[j];
               dp[i][k1+ct] = min(dp[i][k1+ct],temp);    
           }
       }
   }
   ll ans = INF;
   for(ll i=0;i<n;i++)
   {
       for(ll j=0;j<=k;j++)
       {
           ll rem = n-1-i;
           if(rem+j<=k)
                ans = min(ans, dp[i][j]);
       }
   }
   cout<<ans;        
   
   
   return 0;
}  
   