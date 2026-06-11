#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x,k,d; cin>>x>>k>>d;
	ll moves = abs(x)/d; //number of moves in the gg direction
	if(x<0)
	{
		x+=min(k,moves)*d;
		k-=min(k,moves);
	}
	else
	{
		x-=min(k,moves)*d;
		k-=min(k,moves);
	}
	//k moves left to oscillate
	k%=2;
	for(int z=0;z<k;z++)
	{
		if(x<0)
		{
			x+=d;
		}
		else
		{
			x-=d;
		}
	}
	cout<<abs(x)<<'\n';
}