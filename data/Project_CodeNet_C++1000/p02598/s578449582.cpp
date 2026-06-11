#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mp make_pair

int main()
{
	ll n,k; cin >> n >> k;
	vector <ll> v;
	// make_heap hp;
	forn(i,0,n)
	{
		ll a; cin >> a;
		v.push_back(a);
	}

	ll l = 1; ll r = 1000000005;
	ll mid;
	ll count = 0;

	while(l < r)
	{
		// ll ans = mid;
		mid = l + (r-l)/2;
		count = 0;

		for(ll i : v)
		{
			count += (i-1)/mid;
		}

		if(count > k)
			l = mid + 1;
		else
			r = mid;

		// ll ans = mid;
	}
	
	cout << l << endl;
}