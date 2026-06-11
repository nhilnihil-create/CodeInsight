#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;

ll qpow(ll x, int b)
{
	ll ret = 1;
	while(b)
	{
		if(b & 1)
			ret *= x;
		b >>= 1;
		if(!b)
			break;
		x = x * x;
		//b >>= 1;
	}
	return ret;
}
vector<pair<ll, int> > facs;

int main()
{
	cin>>N;
	ll sqt = sqrt(N);
	for(ll i = 2; i <= sqt; ++i)
	{
		if(N % i == 0)
		{
				ll NN = N;
				ll exp = 0;
				while(NN % i == 0)
				{
						NN /= i;
						++exp;
				}
				facs.push_back(make_pair(i, exp));
				if(i * i != N)
				{
						ll NN = N;
						ll exp = 0;
						ll j = N / i;
						while(NN % j == 0)
						{
								NN /= j;
								++exp;
						}
						facs.push_back(make_pair(j, exp));
				}
		}
	}
	
	ll ans = (N == 2)?1:2;
	for(auto& p: facs)
	{
			ll K = p.first;
			int exp = p.second;
			ll NN = N;
			NN /= qpow(K, exp);
			if((NN - 1) % K == 0)
				++ans;
	}
	ll M = N - 1;
	sqt = sqrt(M);
	for(ll i = 2; i <= sqt; ++i)
	{
			if(M % i == 0)
			{
				if(i * i == M)
					ans++;
				else
					ans += 2;
			}
			
	}
	cout<<ans<<endl;
}
