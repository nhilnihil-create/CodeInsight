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
int n;
pair<int,int> a[2001];
int dp[2001][2001];
int32_t main() {
    nitin;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1,greater<>());
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]+a[i].first*abs(a[i].second-i);
//        cout<<dp[i][0]<<" "<<i<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=dp[0][i-1]+a[i].first*abs((n-i+1)-a[i].second);
//        cout<<dp[0][i]<<" "<<i<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i+j<=n)
            dp[i][j]=max(dp[i-1][j]+a[i+j].first*abs(a[i+j].second-i),dp[i][j-1]+a[i+j].first*abs((n-j+1)-a[i+j].second));
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        ans=max(ans,dp[i][n-i]);
    }
    cout<<ans<<endl;
    return 0;
}