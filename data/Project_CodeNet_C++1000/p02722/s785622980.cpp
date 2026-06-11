
		#include <bits/stdc++.h>
		using namespace std;
		
		typedef long long ll;
		#define pi 3.14159265 
		#define EPS 1e-8
		
		#define mod 1000000007
		#define fi first
		#define se second
		#define mp make_pair
		#define pb push_back
		#define endl "\n"

		const ll INF=(ll)2e18;
		
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
			 cin.tie(NULL);
			
			 ll n;
			 cin>>n;
			 ll n1=n;
			 ll ans=0;
			 for(ll i=2;i*i<=n;i++)
			 {
				ll n2=n;
				if(n2%i!=0)
					continue;
				 while(n2%i==0)
				 {
					 n2/=i;
				 }
				 if(n2%i==1)
					ans++;
				if(i*i==n1)
						continue;
					n2=n;
					ll j=n/i;
					while(n2%j==0)
					{
						n2/=j;
					}
					if(n2%j==1)
						ans++;
			 }
			
			 
			 n1=n-1;
			 set<ll> s;
			 for(ll i=1;i*i<=n1;i++)
			 {
				 if(n1%i==0)
				 {
					 s.insert(i);
					 s.insert(n1/i);
				 }
			 }
			 ans+=s.size();
		
			 cout<<ans;
		}
