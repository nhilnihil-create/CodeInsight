#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
typedef pair<ll,ll> ipair;
#define F first
#define S second
 


int main() {
    // ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);
    
    
    ll n,i,j,p,k,m,t,ans=0;
    cin>>n>>t;
    long long int dp[3009][3009];
    // memset(dp, 0, sizeof(dp)); 
    for(i=0;i<3009;i++)
    {
        for(j=0;j<3009;j++)
        dp[i][j]=0;
    }
    vector<ll> a(n),b(n);
    vector<pair<ll,ll> > val(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        val[i].F=a[i];
        val[i].S=b[i];
    }
    sort(val.begin(),val.end());
    for(i=0;i<n;i++)
    {
        a[i]=val[i].F;
        b[i]=val[i].S;
    }
    for(i=0;i<t;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i+a[j]<t)
            {
                dp[j+1][i+a[j]] = max(dp[j][i]+b[j],dp[j+1][i+a[j]]);
            }
            
            dp[j+1][i] = max(dp[j][i],dp[j+1][i]);
            
        }
    }
    
    for(i=0;i<n;i++)
    {
        ans = max(ans , dp[i][t-1] + b[i]);
    }
    cout<<ans<<endl;
    
    // for(i=0;i<n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    
    return 0;
}