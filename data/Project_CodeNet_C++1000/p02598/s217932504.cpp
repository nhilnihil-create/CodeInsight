#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mod 1000000007
#define vll vector<ll>
#define inf 1e18
#define pll pair<ll,ll>
#define ff first 
#define ss second 
#define PI acos(-1)
using namespace std;
ll n,k;
ll a[200005];
ll check(ll x)
{
	ll sum=0;
	for(ll i=1;i<=n;i++)
	{
		//if(a[i]>x)
		sum+=(ceil(1.0*(a[i])/x) -1);
	}
	if(sum<=k)return 1;
	return 0;
}
int main() 
{
    fastio; 
    ll T=1;
    //cin>>T; 
    while(T--)
    { 	
    	cin>>n>>k;
    	for(ll i=1;i<=n;i++)cin>>a[i];
    	ll lo=1,hi=*max_element(a+1,a+n+1);
    	while(lo<hi)
    	{
    		ll mid=(lo+hi)/2;
    		if(check(mid))
    		{
    			hi=mid;
			}
			else
			{
				lo=mid+1;
			}
		}
		cout<<hi<<endl;
	}
}
 