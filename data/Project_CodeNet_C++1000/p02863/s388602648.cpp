#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pb push_back
#define mk make_pair
#define mod 998244353
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define loop(i,l,r) for(int i=l;i<r;i++)
#define all(x) x.begin(),x.end()

int main()
{
    ios::sync_with_stdio(0) ;
    cin.tie(0); 
    int n,t,a,b;
    cin>>n>>t;int aa=0;int bb=0;
    vector<pair<int,int>> v;v.pb(mk(0,0));
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;aa+=a;bb+=b;
        v.pb(mk(a,b));
    }
    sort(v.begin(),v.end());
    int dp[n+1][t];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<t;j++)
        dp[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<t;j++)
        {
            if(v[i].first>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],v[i].second+dp[i-1][j-v[i].first]);
            }
            
        }
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        ans=max(ans,dp[i][t-1]+v[i+1].second);
    }ans=max(ans,dp[n][t-1]);
    cout<<ans;
    return 0;
}
//make all values ll
