/*Whose woods these are I think I know.
His house is in the village though;
He will not see me stopping here
To watch his woods fill up with snow.

My little horse must think it queer
To stop without a farmhouse near
Between the woods and frozen lake
The darkest evening of the year.

He gives his harness bells a shake
To ask if there is some mistake.
The only other sound’s the sweep
Of easy wind and downy flake.

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int a[2020];
int b[2020];
int dp[2020][2020];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,m=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i)
        cin>>b[i];
    for(int i=0;i<=n;++i)
        dp[i][0]=1;
    for(int i=0;i<=m;++i)
        dp[0][i]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            if(a[i]!=b[j])
                dp[i][j]-=dp[i-1][j-1];
            dp[i][j]%=MOD;
            if(dp[i][j]<0)
                dp[i][j]+=MOD;
        }
    cout<<dp[n][m]<<endl;
}
