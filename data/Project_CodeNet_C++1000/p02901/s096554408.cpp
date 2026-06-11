#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn =1e5+10;
const int mod=1e9+7;

int dp[1010][5010];




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=1005;i++)
    {
        for(int j=0;j<=5005;j++)
            dp[i][j]=1e9;
    }
    dp[0][0]=0;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        int sum=0;
        for(int j=1;j<=b;j++)
        {
            int c;
            cin>>c;
            int x=1<<(c-1);
            sum+=x;
        }

        //cout<<sum<<" here"<<'\n';
        for(int j=0;j<=(1<<n)-1;j++)
        {
            int temp=0;
            for(int x=0;x<=12;x++)
            {
                if(((j>>x)&1)&&((sum>>x)&1)==0)
                {
                    temp+=(1<<x);
                }
            }
            /*if(i==2&&j==3)
                cout<<sum<<" here"<<'\n';*/
            //cout<<temp<<" here"<<'\n';
            dp[i][j]=min(dp[i-1][j],dp[i-1][temp]+a);

        }
    }
    /*for(int i=1;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }*/
    if(dp[m][(1<<n)-1]==1e9)
        dp[m][(1<<n)-1]=-1;
    cout<<dp[m][(1<<n)-1]<<'\n';

}
