	#include <bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	#define PI 3.14159265358979
	#define EPS 1e-8
	#define mod 
	#define fi first
	#define se second
	#define mp make_pair
	#define pb push_back
	#define endl "\n"
		 
	const ll INF=1e15;	
	const int N=2e5+50;
	 

	 
	long long binpow(long long a, long long b, long long m) {
		a %= m;
		long long res = 1;
		while (b > 0) {
			if (b & 1)
				res = res * a % m;
			a = a * a % m;
			b >>= 1;
		}
		return res;
	}
	
	
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);cout.tie(0);
		
		ll n;
		cin>>n;
		
		vector<ll> a(n+1),b(n+1);
		vector<ll> v1,v2;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
			v1.pb(a[i]);
			v2.pb(b[i]);
		}
		
		sort(v1.begin(),v1.end());
		
		sort(v2.begin(),v2.end());
		
		if(n%2==1)
		{
			ll lo=v1[n/2];
			ll hi=v2[n/2];
			
			cout<<(hi-lo+1);
		}
		else
		{
			ll lo=v1[n/2-1];
			ll hi=v1[n/2];
			
			ll l1=(hi+lo);
			
			lo=v2[n/2];
			hi = v2[n/2-1];
			
			ll l2=(hi+lo);
			
	
			cout<<(l2-l1+1)<<endl;
			
		}
		
		
		
	}
		
		
	
