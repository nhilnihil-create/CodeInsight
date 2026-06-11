#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size() 
ll a[2005],dp[2005][2005],b[2005];
bool vis[2005][2005];
ll N;
ll solve(ll idx,ll l,ll r)
{
	if(idx==N+1)
		return 0;
	if(vis[idx][l])
		return dp[idx][l];

	vis[idx][l]=true;
	

	ll left=solve(idx+1,l+1,r)+b[a[idx]]*(a[idx]-l);
	ll right=solve(idx+1,l,r-1)+b[a[idx]]*(r-a[idx]);

	return dp[idx][l]=max(left,right);
}

int main()
{
    ios_base::sync_with_stdio(false);
	ll n,i,j,k,x,y,t,m;
	vector<pll>v;
	cin >> n;
	N=n;
	for(i=1;i<=n;i++)
	{
		cin >> b[i];
		v.pb(mp(b[i],i));
	}
	sort(all(v));
	reverse(all(v));
	for(i=1;i<=n;i++)
		a[i]=v[i-1].ss;

	cout<<solve(1,1,n)<<endl;
}