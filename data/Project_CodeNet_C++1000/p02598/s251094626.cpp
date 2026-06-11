#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree < pairs ,  null_type , greater<pairs>,  rb_tree_tag ,  tree_order_statistics_node_update > 
#define ll long long
#define lld long double
#define vc vector<ll>
const ll MOD=(1e9 +7);
typedef pair<ll,ll>pairs;
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;b--;}a=(a*a)%MOD;b>>=1;}
    return res;}

int main() {
	// your code goes here
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll t,n,i,j,k,l,c,f;
	cin>>n>>k;
	vc a(n);
	for(i=0;i<n;i++)cin>>a[i];
	ll low=1;ll high=*max_element(a.begin(),a.end()),mid,ans=MOD;
	while(high>=low)
	{
	    mid=(high+low)/2;
	    c=0;
	    for(auto x:a)
	        c+=(x-1)/mid;
	    if(c<=k)
	    {
	        ans=min(ans,mid);
	        high=mid-1;
	    }
	    else low=mid+1;
	}
	cout<<ans;
	return 0;
}
