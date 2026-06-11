#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+100;


ll a[N];
ll n;

int main()
{
	scanf("%lld",&n);
	ll ans = 0,maxx = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]<maxx) ans+=(maxx - a[i]);
		maxx = max(maxx,a[i]);
	}
	cout << ans << endl;
	return 0;
}