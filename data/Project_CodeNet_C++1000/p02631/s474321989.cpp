#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 9223372036854775807;
const ll MOD = 1000000007;
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define o0(a) cout<<a<<" "
#define o1(a) cout<<a<<"\n"
#define o2(a, b) cout<<a<<" "<<b<<"\n"
#define o3(a, b, c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define i1(a) cin>>a
#define i2(a, b) cin>>a>>b
#define i3(a, b, c) cin>>a>>b>>c
#define fi first
#define se second

ll power(ll a, ll b, ll z = MOD)
{
	ll res = 1;
	a = (a%z);
	while(b)
	{
		if(b&1)
			res = (res*a)%z;
		a = (a*a)%z;
		b = b>>1;
	}
	return res;
}

ll inverse(ll a, ll z = MOD)
{
	return power(a, z-2, z);
}

ll gcd(ll a, ll b)
{
	ll temp;
	if(a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while(b)
	{
		temp = b;
		b = a - b;
		a = temp;
	}
	return a;
}

ll extend(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll g = extend(b, a%b, x1, y1);
	x = y1;
	y = x1- (a/b)*y1;
	return g;
}

ll mat_power(ll a, ll b, ll c, ll d, ll n, ll z = MOD)
{
	ll a0 = 1, b0 = 0, c0 = 0, d0 = 1;
	while(n)
	{
		if(n&1)
		{
			ll a1 = a0, b1 = b0, c1 = c0, d1 = d0;
			a0 = (a1*a + b1*c)%z;
			b0 = (a1*b + b1*d)%z;
			c0 = (c1*a + d1*c)%z;
			d0 = (c1*b + d1*d)%z;
		}
		ll a1 = a, b1 = b, c1 = c, d1 = d;
		a = (a1*a1 + b1*c1)%z;
		b = (a1*b1 + b1*d1)%z;
		c = (c1*a1 + d1*c1)%z;
		d = (c1*b1 + d1*d1)%z;
		n = n>>1;
	}
	return c0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	// i1(t);
	while(t--)
	{
		int n;
		i1(n);
		int aray[n];
		for(int i=0;i<n;i++)
			i1(aray[i]);
		int ans[n];
		int sum = aray[0];
		for(int i=1;i<n;i++)
			sum = sum^aray[i];
		for(int i=0;i<n;i++)
			ans[i] = sum^aray[i];
		for(int i=0;i<n;i++)
			o0(ans[i]);
		cout<<"\n";
	}
	return 0;
}