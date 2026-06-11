#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF 1e8;
typedef long long ll;
ll mod = 998244353;
long long fast_exp(long long a, long long b)
{
    if(b == 0)
	   return 1;
    else
    {
	   long long res = 1;
	   res = fast_exp(a,b/2);
	   res = (res*res)%mod;
	   if(b%2 == 1)
		  res = (res*a)%mod;
	   return res;
 
    }
}
const ll N = 1e6;




int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll n;
	cin>>n;
	ll p[n+1] , pos[n+1];
	for(ll i = 1; i<=n ; i++)
		{
			cin>>p[i];
			pos[p[i]] = i;
		}
	ll rfm[n+1], rsm[n+1], lfm[n+1], lsm[n+1];
	set <ll> pset;
	for(ll i = n ; i>=1 ; i--)
	{
		ll cpos = pos[i];
		auto itr = pset.lower_bound(pos[i]);
		if(itr == pset.end())
		{
			rfm[i] = n+1;
			rsm[i] = n+1;
		}
		else
		{
			rfm[i] = *itr;
			itr++;
			if( itr == pset.end() )
				{
					rsm[i] = n+1;
				}
			else
				{
					rsm[i] = *itr;

				}
		}
		pset.insert(pos[i]);
	}
	pset.clear();
	for(ll i = n ; i>=1 ; i--)
	{
		ll cpos = pos[i];
		auto itr = pset.lower_bound(-pos[i]);
		if(itr == pset.end())
		{
			lfm[i] = 0;
			lsm[i] = 0;
		}
		else
		{
			lfm[i] = -(*itr);
			itr++;
			if(itr == pset.end())
			{
				lsm[i] = 0;
			}	
			else
			{
				lsm[i] = -(*itr);
			}
		}
		pset.insert(-pos[i]);
	}
	// for(ll i = 1; i<=3 ; i++)
	// {
	// 	cout<<"rfm : "<<rfm[i];
	// 	cout<<"		rsm : "<<rsm[i];
	// 	cout<<"		lfm : "<<lfm[i];
	// 	cout<<"		lsm : "<<lsm[i];
	// 	cout<<endl;

	// }

	ll sum = 0;
	for(ll i = 1; i<=n ; i++)
	{
		sum += i * (pos[i] - lfm[i]) * (rsm[i] - rfm[i]);
		sum += i * (rfm[i]-pos[i]) * (lfm[i] - lsm[i]);
	}

	cout<<sum<<endl;

	return 0;
	
}