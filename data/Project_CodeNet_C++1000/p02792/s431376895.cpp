#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
ll dp[11][11];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,t,n,b,c,d,a,l,r;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        x=i;
        y=x%10;
        while(x/10!=0)
            x/=10;
        dp[x][y]++;
    }
    ll ans=0;
    for(i=1; i<=9; i++)
        for(j=1; j<=9; j++)
            ans+=dp[i][j]*dp[j][i];
    cout<<ans<<'\n';
}

