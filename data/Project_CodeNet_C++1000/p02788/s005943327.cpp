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
		
		map<ll,ll> bit;
		
		void update(ll idx,ll val)
		{
			while(idx<=1e9)
			{
				bit[idx]+=val;
				idx+=(idx & -idx);
			}
		}
		
		ll query(ll idx)
		{
			ll sum=0;
			
			while(idx>0)
			{
				sum+=bit[idx];
				idx-=(idx & -idx);
			}
			return sum;
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
			
			for(auto i:v)
			{
				ll val=query(i.fi);
				if(val<i.se)
				{
					//cout<<i.fi<<" "<<val<<endl;
					ll mov=(i.se-val+a-1)/a;
					ans+=mov;
					val=mov*a;
					update(i.fi,val);
					update(i.fi+2*d+1,-val);
				}
				
			}
			cout<<ans;
			
			
			
			
		}
			
			
		
