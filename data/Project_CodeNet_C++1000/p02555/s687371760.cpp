#include<bits/stdc++.h>
using namespace std;
#define l long int 
#define ll long long int 
vector<int>adj[1000001];
int vis[1000001];
int n=2005;
int dp[2005];
int fact[1000001];
#define mod 1000000007 
//int dp[n];
ll sequence_sum(int a)
{
    if(a==0)
     return 1ll;
    else if(a==1 || a==2)
        return 0ll;
    else if(a==3 || a==4 || a==5)
        return 1ll;
    else if(dp[a]!=-1)
            return dp[a];
    else
    {
        ll total=0;
        for(int i=3;i<=a;i++)
        {
            if((a-i)>=0)
            {
                total=(total+sequence_sum(a-i))%mod; 
            }
        }
    return dp[a]=total;
    }
}
int main()
{
    int s;
    cin>>s;
    for(int i=0;i<=n;i++)
    {
        dp[i]=-1;
    }
    dp[0]=0;
    // sequence_sum(s);
    cout<<sequence_sum(s)<<"\n";
    
    return 0;
}