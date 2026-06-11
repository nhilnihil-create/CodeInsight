#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=1e9+7;
int a[maxn];
int c[maxn];
int dp[1005][(1<<12)+5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>a[i]>>x;
        int temp=0;
        for(int j=1;j<=x;j++)
        {
            int y;
            cin>>y;
            y=1<<(y-1);
            temp|=y;
        }
        c[i]=temp;
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            dp[i][j]=1e9;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            int k=j|c[i];
            dp[i][k]=min(dp[i][k],dp[i-1][j]+a[i]);
        }
    }
    if(dp[m][(1<<n)-1]==1e9)
        cout<<-1<<'\n';
    else
        cout<<dp[m][(1<<n)-1]<<'\n';


}
