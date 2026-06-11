#include<bits/stdc++.h>
// __builtin_ctz : no of trailing zeros
#define ll long long
#define pp pair<ll,ll>
#define mod 1000000007
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define sa(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define scan() int n; cin>>n ; int a[n]; for(int i = 0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) cout<<a[i]<<' '
using namespace std;
ll max(ll x, ll y)
{
    return x>y ? x : y;
}
ll min(ll x, ll y)
{
    return x<y ? x : y;
}
void _(ll&a , ll b)
{
    a=(a%mod+b%mod)%mod;
    a=(a+mod)%mod;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;cin >> n >> m;
    ll s[n],t[m];
    for (int i = 0; i < n; ++i)
    {
    	cin >> s[i];
    }
    for (int i = 0; i < m; ++i)
    {
    	cin >> t[i];
    }
    ll dp[n+1][m+1];memset(dp,0,sizeof(dp));/*dp[0][0]=1;*/
    for(ll i=1;i<=n;i++)
    {
    	for(ll j=1;j<=m;j++)
    	{
    		_(dp[i][j],dp[i-1][j]);
    		_(dp[i][j],dp[i][j-1]);
    		_(dp[i][j],-dp[i-1][j-1]);
    		//+dp[i][j-1]-dp[i-1][j-1];
    		if(s[i-1]==t[j-1])_(dp[i][j],1+dp[i-1][j-1]);
    	}
    }
    cout << (dp[n][m]+1)%mod;
    }