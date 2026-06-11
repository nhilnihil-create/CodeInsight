#include<bits/stdc++.h>
typedef  long long int ll;
typedef  long double ld;
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define mod 1000000007
#define F first
#define S second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
//recursions\
#pragma comment(linker, "/stack:200000000")
//loops\
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;
ll dp[2005][2005];
int main()
{
	sync;
	ll n;
	cin>>n;
	vector<pair<ll,ll> >v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i].F;
		v[i].S=i+1;
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ll val=v[i-1].F,idx=v[i-1].S;
		for(ll j=1;j<=i;j++)
		{
			dp[j][i-j]=max(dp[j][i-j],dp[j-1][i-j]+abs(j-idx)*val);
			dp[i-j][j]=max(dp[i-j][j],dp[i-j][j-1]+abs(n+1-j-idx)*val);		
		}
	}
	
	for(ll i=0;i<=n;i++)
		ans=max(ans,dp[i][n-i]);
		
	cout<<ans;
}