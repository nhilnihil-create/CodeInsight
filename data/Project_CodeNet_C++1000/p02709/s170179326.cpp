/*input
6
8 6 9 1 2 1
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

#define rep(i,j,n) for(i=j;i<n;i++)
#define repi(i,j,n) for(i=j;i>n;i--)
#define inf 100001
#define M 1000000007
#define ll long long
#define ld long double
#define vll vector<long long>
#define vi vector<int>
#define pll pair<long long,long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
#define vpll vector<pair<long long,long long> >
#define pb push_back
#define pf pop_front
#define F first
#define S second
#define endl '\n'

using namespace std;
using namespace __gnu_pbds; 

template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


ll power(ll a,ll m,ll mod){
	ll ans=1;
	while(m){
		if(m%2){
			ans*=a;
			ans%=(mod);
		}
		a=(a*a)%(mod);
		m>>=1;
	}
	return ans;
}


void init(ll* a,ll n,ll val){
	for(ll i=0;i<n;i++)
		a[i]=val;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	ll t=1,i,j;
	ll n;
	cin>>n;
	ll dp[n+2][n+2];
	memset(dp,0,sizeof(dp));
	ll a;
	vpll v;
	rep(i,0,n)cin>>a,v.pb({a,i});
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());

	rep(i,0,n){
		rep(j,1,i+2){
			dp[j][n-(i+1-j)+1]=max(dp[j][n-(i+1-j)+1],dp[j-1][n-(i+1-j)+1]+(abs(v[i].S-(j-1)))*v[i].F);
		}
		repi(j,n,n-i-1){
			dp[i+j-n][j]=max(dp[i+j-n][j],dp[i+j-n][j+1]+abs(v[i].S-j+1)*v[i].F);
		}
	}
	ll ans=0;
	rep(i,0,n+1)ans=max(ans,dp[i][i+1]);
	cout<<ans<<endl;
	return 0;
}


