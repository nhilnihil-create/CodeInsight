#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
	if (a % b == 0) return b;
	return gcd(b,a%b);
}

int main()
{
	ll k,ans=0,res; cin >> k;
	for (ll a=1; a<=k; a++)
		for (ll b=1; b<=k; b++)
			for (ll c=1; c<=k; c++)
				res = gcd(a,b), res = gcd(res,c), ans += res;

	cout<<ans<<"\n";

	return 0;
}