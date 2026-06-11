#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define pii pair<ll,ll>
#define sz(v) (v).size()
#define srt(v) sort(v.begin(),v.end())
#define ull unsigned long long
#define tell(a) cout<<a<<" "
#define el cout<<endl
#define rev(v) reverse(v.begin(),v.end())
#define rep(i,a,n) for(int i=a;i<n;i++)
#define M 1000000007
ll power(ll x, ll y, ll p){ll res = 1;x = x % p;while (y > 0){   if (y & 1)res = (res*x) % p;y = y>>1;
x = (x*x) % p;}return res;}
vector<pii>v;
ll dp[2001][2001],n;
ll fu(int i,int j)
{
	if(i==n)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	dp[i][j]=v[i].ff*abs(v[i].ss-j)+fu(i+1,j+1);
	dp[i][j]=max(dp[i][j],v[i].ff*abs(v[i].ss-(n-i+j-1))+fu(i+1,j));
	return dp[i][j];
}
int main()
{
	IOS;
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	rep(i,0,n)
	{
		int c;
		cin>>c;
		v.pb(make_pair(c,i));
	}
	sort(v.rbegin(),v.rend());
	ll ans=fu(0,0);
	cout<<ans;
}