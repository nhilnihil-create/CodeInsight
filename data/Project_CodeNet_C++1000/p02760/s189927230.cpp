#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int dp[3][3];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>dp[i][j];
        }
    }

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n;i++)
    {
        for(int x=0;x<3;x++)
        {
           for(int y=0;y<3;y++)
           {
               if(dp[x][y]==arr[i])
                dp[x][y]=0;
           }
        }
    }

    for(int i=0;i<3;i++)
    {
        if(dp[i][0]==0 && dp[i][1]==0 && dp[i][2]==0)
        {
            cout<<"Yes\n";
            return;
        }
    }

    for(int i=0;i<3;i++)
    {
        if(dp[0][i]==0 && dp[1][i]==0 && dp[2][i]==0)
        {
            cout<<"Yes\n";
            return;
        }
    }

    // diagonal matching

    if(dp[0][0]==0 && dp[1][1]==0 && dp[2][2]==0)
    {
        cout<<"Yes\n";
        return ;
    }

    if(dp[0][2]==0 && dp[1][1]==0 && dp[2][0]==0)
    {
        cout<<"Yes\n";
        return;
    }

    cout<<"No\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        solve();

    return 0;
}
