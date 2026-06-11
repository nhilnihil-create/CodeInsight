#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mod1 1000000007
#define ff first
#define ss second
#define INF INT_MAX
#define INFLL LLONG_MAX
typedef long long int ll;
// #define intLL unsigned long long int//used when x<2^64-1 && x>0
#define int long long//used when x<2^63-1
int fact[200005];
int power(int a, int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
        {
            res*=a;
            res%=mod1;
        }
        a*=a;
        a%=mod1;
        b/=2;
    }
    return res;
}
int add(int a, int b)
{
    return (0LL+a+b)%mod1;
}
int sub(int a, int b)
{
    return add(a, mod1-b);
}
int mul(int a, int b)
{
    return (1LL*a*b)%mod1;
}
int inv(int x)
{
    return power(x, mod1-2);
}
int nCr(int n, int r)
{
    return mul(fact[n], inv(mul(fact[r], fact[n-r])));
}
int cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.ff>b.ff);
}
int32_t main()
{

    IOS;
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v.pb({x, i});
    }
    sort(v.begin(), v.end(), cmp);
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));//dp[i][j] means i elements have been placed with j elements on the left
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i][j+1]=max(dp[i][j+1], dp[i-1][j]+v[i-1].ff*abs(v[i-1].ss-(j+1)));//putting i th one at j+1
            dp[i][j]=max(dp[i][j], dp[i-1][j]+v[i-1].ff*abs(v[i-1].ss-(n-(i-1-j))));
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx, dp[n][i]);
    }
    cout<<mx<<"\n";
    return 0;
}