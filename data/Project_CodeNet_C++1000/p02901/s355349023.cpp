#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int n,m;
int cost[1001];
int which[1001];
int dp[1001][1<<13];
int32_t main() {
    nitin;
    cin>>n>>m;
    ci(m)
    {
        cin>>cost[i];
        int p;
        cin>>p;
        cj(p)
        {
            int q;
            cin>>q;
            --q;
            which[i]|=(1<<q);
        }
    }
    for(int i=0;i<m;i++)
    {
        dp[i][0]=0;
        for(int j=1;j<(1<<12);j++)
        {
            if((j|which[i])==which[i])
                dp[i][j]=cost[i];
            else
                dp[i][j]=inf;
        }
        for(int j=1;j<(1<<12) && i>0;j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j]);
            dp[i][j]=min(dp[i-1][j],dp[i-1][j&(~which[i])]+cost[i]);
        }
    }
    if(dp[m-1][(1<<n)-1]==inf)
        cout<<-1<<endl;
    else
        cout<<dp[m-1][(1<<n)-1]<<endl;
    return 0;
}