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
		
					
			ll n,m;
			cin>>n>>m;
			
			
			vector<ll> a(m+1,0),b(m+1,0);
			
			for(ll i=1;i<=m;i++)
			{
				ll b1;
				cin>>a[i]>>b1;
				ll tot=0;
				for(ll j=0;j<b1;j++)
				{
					ll c;
					cin>>c;
					tot|=(1LL<<(c-1));
				}
				
				b[i]=tot;
			}
			
			ll dp[(1LL<<12)];
			
			for(ll i=0;i<(1LL<<12);i++)
			{
				dp[i]=INF;
			}
			
			dp[0]=0;
			
			for(ll i=0;i<(1LL<<n);i++)
			{
				if(dp[i]==INF)
					continue;
				for(ll j=1;j<=m;j++)
				{
						dp[i|b[j]]=min(dp[i|b[j]],dp[i]+a[j]);
					
				}
			}
			
			ll ans=dp[(1LL<<n)-1];
			
			if(ans==INF)
				cout<<-1;
			else
				cout<<ans;
			
		}
			
			
		
