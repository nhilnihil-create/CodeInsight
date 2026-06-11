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
			
			vector<ll> v(n+1);
			
			for(ll i=1;i<=n;i++)
			{
				cin>>v[i];
			}
			
			ll dp[3005][3005];
			
			for(ll i=0;i<=n;i++)
			{
				for(ll j=0;j<=m;j++)
				{
					if(j==0)
						{
							dp[i][j]=1;
							continue;
						}
						
					dp[i][j]=0;
				}
			}
			
			for(ll i=1;i<=n;i++)
			{
				for(ll j=1;j<=m;j++)
				{
					dp[i][j]=dp[i-1][j];
					if(j-v[i]>=0)
					{
						dp[i][j]+=(dp[i-1][j-v[i]])*modinverse(2LL,mod);
						dp[i][j]%=mod;
					}
				}
			}
			
			ll ans=dp[n][m]*binpow(2,n,mod) %mod;
			cout<<ans;
		}
			
			
		
