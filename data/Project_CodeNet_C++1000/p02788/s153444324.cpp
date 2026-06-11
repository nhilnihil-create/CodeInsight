		#include <bits/stdc++.h>
		using namespace std;
		typedef long long ll;
		#define PI 3.14159265358979
		#define EPS 1e-8
		#define mod  998244353
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
		
		ll modinverse(ll a,ll m)
		{
			return binpow(a,m-2,m);
		}
		
		
		int main()
		{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);cout.tie(0);
			
			ll n,d,a;
			cin>>n>>d>>a;
			
			vector<ll> x(n),h(n);
			
			vector<pair<ll,ll> > v(n);
			for(ll i=0;i<n;i++)
			{
				cin>>x[i]>>h[i];
				v[i]={x[i],h[i]};
			}
			
			ll ans=0;
			sort(v.begin(),v.end());
			
			
			vector<pair<ll,ll> > v1;
			
			ll val=0;
			ll idx=0;
			for(auto i:v)
			{
				while(idx<v1.size() && v1[idx].fi<=i.fi)
				{
					val+=v1[idx].se;
					idx++;
				}
			
				if(val<i.se)
				{
					ll mov=(i.se-val+a-1)/a;
					ans+=mov;
					val+=mov*a;
					ll val1=mov*a;
					v1.pb({i.fi+2*d+1,-val1});
				}
				
			}
			cout<<ans;
			
			
			
			
		}
			
			
		
