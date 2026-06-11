#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll dp[2005][2005];
int a[2005],b[2005],n,m;
ll ADD(ll x,ll y)
{
    return (x+y)%MOD;
}
ll SUB(ll x,ll y)
{
    return ((x-y)+MOD)%MOD;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
    {
        cin>>b[i];
    }
    dp[0][0]=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            dp[i][j]=ADD(dp[i-1][j],dp[i][j-1]);
            if(a[i]!=b[j])
                dp[i][j]=SUB(dp[i][j],dp[i-1][j-1]);
            else
                dp[i][j]=ADD(dp[i][j],1);
        }
    cout<<(dp[n][m]+1)%MOD<<endl;





    return 0;
}
