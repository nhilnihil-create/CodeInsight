#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define mod 1000000007
#define PI 3.1415926535
using namespace std;
ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	else if (y % 2 == 0)
		return power(x, y / 2) * power(x, y / 2);
	else
		return x * power(x, y / 2) * power(x, y / 2);
}
ll modExpo(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modExpo((x*x)%mod,n/2);
    else                            
        return (x*modExpo((x*x)%mod,(n-1)/2))%mod;
}
ll sum(ll n)
{
	ll s=0;
	while(n)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	ll n;
	cin>>n;
	ll a,b;
	ll ans;
	ll mx1=INT_MIN, mx2=INT_MIN;
	ll mn1=INT_MAX, mn2=INT_MAX;
	for(ll i=0;i<n;i++)
	{
		cin>>a>>b;
		mn1=min(mn1,a+b);
		mn2=min(mn2,a-b);
		mx1=max(mx1,a+b);
		mx2=max(mx2,a-b);
	}
	ll ans1=mx1-mn1;
	ll ans2=mx2-mn2;
	ans=max(ans1,ans2);
	cout<<ans<<endl;
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}