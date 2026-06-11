/**   
 *   Author:    @glaucoacassioc
 *   Created on 11.09.2020, 15:32:16
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

set<ll> divisors;
ll n;
ll ans;

void solve(ll divi)
{
	ll tri = n;
	if(divi == 1)
		return;
	while(tri % divi == 0)
		tri/=divi;
	if(tri % divi == 1)
		++ans;	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
   			solve(i);
   			divisors.insert(i);
   			if(i * i != n)
   			{
   				solve(n / i);
   				divisors.insert(n/i);
   			}
		}
	}
	--n;
	for(ll i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			if(divisors.find(i) == divisors.end())
				++ans;
			if(i * i != n)
			{
				if(divisors.find(n/i) == divisors.end())
					++ans;
			}
		}
	}
	cout << ans << endl;

	return 0;
}             
