//1183F
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define int long long
const int MOD=1e9+7;
const int N=1e2+10;
char a[N][N];
int dp[N][N];
int32_t main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)
            {
                dp[i][j]=(a[i][j]=='#');
            }
            else if(i==1)
            {
                if(a[i][j]=='#'&&a[i][j-1]=='.')
                {
                    dp[i][j]=dp[i][j-1]+1;
                }
                else 
                    dp[i][j]=dp[i][j-1];
            }
            else if(j==1)
            {
                if(a[i][j]=='#'&&a[i-1][j]=='.')
                {
                    dp[i][j]=dp[i-1][j]+1;
                }
                else 
                    dp[i][j]=dp[i-1][j];
            }
            else
            {
                int x=dp[i][j-1];
                int y=dp[i-1][j];
                if(a[i][j]=='#'&&a[i-1][j]=='.')
                    y++;
                if(a[i][j]=='#'&&a[i][j-1]=='.')
                    x++;
                dp[i][j]=min(x,y);
            }

        }
    }
    cout<<dp[n][m]<<endl;
    



      
}