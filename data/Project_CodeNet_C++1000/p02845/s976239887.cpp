#include<bits/stdc++.h>
using namespace std;
    
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    
#define int long long
#define double long double
    
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()
    
#define ff first
#define ss second
#define mp make_pair
         
#define pb push_back
#define endl "\n" 
         
#define f(i,l,r) for(int i=l;i<=r;i++)
#define rf(i,r,l) for(int i=r;i>=l;i--)    

#define bp __builtin_popcountll
#define inf 1e15
    
const int N=1e5+5;
const int M=1e9+7;
int dp[N],a[N];
int n;
int x=0,y=0,z=0;
int go(int p)
{
	if(p==n) return 1;
	if(dp[p]!=-1) return dp[p];
	int cnt=0;
	int need=a[p];
	if(x==need) cnt++;
	if(y==need) cnt++;
	if(z==need) cnt++;
	if(cnt==0)
	return 0;
	if(x==need){
		x++;
	}
	else if(y==need)
	{
		y++;
	}
	else
	{
		z++;
	}
	int ans=1;
	ans=(cnt*go(p+1))%M;
	dp[p]=ans;
	return ans;
}
void solve()
{
	cin>>n;
	f(i,0,n-1) cin>>a[i];
	memset(dp,-1,sizeof(dp));
	int res=go(0);
	cout<<res;
}
signed main()  
{
	FAST
    int t=1;
    // cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
    	// cout<<"Case #"<<tc<<": ";
    	solve();
    }
}
