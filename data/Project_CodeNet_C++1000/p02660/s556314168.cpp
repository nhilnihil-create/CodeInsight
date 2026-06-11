#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector <ll> primes;
ll divi[1000005];
vector <ll> fact;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll i,j,k,l,m,n,t;

	cin >> n;

	if(n == 1)
	{
		cout << 0 << '\n';
		return 0;
	}

	for(i=2;i<1000005;i++)
	{
		for(j=i+i;j<1000005;j+=i)
		{
			divi[j] = -1;
		}

	}

	for(i=2;i<1000005;i++)
	{
		if(divi[i] != -1)
			primes.push_back(i);
	}

	for(i=0;i<primes.size();i++)
	{
		if(n%primes[i] == 0)
		{
			// cout << primes[i] << '\n';
			l = 0;
			while(n%primes[i] == 0)
			{
				n = n/primes[i];
				l++;
			}
			// cout << n << '\n';
			fact.push_back(l);
		}
	}

	if(n > 1)
		fact.push_back(1);

	ll ans = 0;

	for(i=0;i<fact.size();i++)
	{
		// cout << fact[i] << '\n';
		l = 0;
		k = 1;

		while(fact[i] >= l)
		{
			l += k;
			k++;

			if(fact[i] >= l)
				ans++;
			else
				break;
		}

	}


	cout << ans << '\n';
}