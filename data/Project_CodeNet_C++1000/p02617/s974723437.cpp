#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
typedef long long ll;
typedef long double ld;
#define trace(x)  cerr << #x << ": " << x << endl;
#define rep(i,a)  for(ll i=0; i< a; i++)
#define pb push_back
#define vl vector<ll> 
#define rep(i,a)  for(ll i=0; i< a; i++)
const ll N=3*1e5+5;ll mod=998244353;
int main()
{
	fast;
	ll t;t=1;
	while(t--)
	{
		ll n;cin>>n;ll a=(n*(n+1)*(n+2))/6;
		for(ll i=0;i<n-1;i++)
		{
			ll u,v;cin>>u>>v;if(u>v)swap(u,v);
			a-=u*(n-v+1);
		}
		cout<<a;
	}

}