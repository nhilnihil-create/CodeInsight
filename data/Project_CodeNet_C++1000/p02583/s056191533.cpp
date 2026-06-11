#include <bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;
const ll N = 1e5+100;
const ll MOD = 1e9+7;

ll n,m,T;
ll l[110];
int main()
{
	/*scanf("%d",&T);
	while(T--)
	{
	
	 } 
	 */
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&l[i]);
	}
	ll ans = 0;
	for(ll i=1;i<=n;i++)
	for(ll j=i+1;j<=n;j++)
	for(ll k=j+1;k<=n;k++)
	{
		ll a = l[i], b = l[j], c = l[k];
		if(a==b||b==c||a==c)	continue;
		if(a+b>c&&a+c>b&&b+c>a)	ans++;
		
	}	
	printf("%lld\n",ans);
	return 0;
}