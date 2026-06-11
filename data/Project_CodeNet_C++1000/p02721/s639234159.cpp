
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
			
			ll n,k,c;
			cin>>n>>c>>k;
			string s;
			cin>>s;
			vector<ll> pref(n+1,0);
			vector<ll> suff(n+2,0);
			for(ll i=1;i<=n;i++)
			{
				
				if(s[i-1]=='o')
				{
					pref[i]=max(pref[i-1],pref[i]);
					if((i-k-1)>=0)
					{
						pref[i]=max(pref[i],pref[i-k-1]+1);
					}
				}
				else
					pref[i]=pref[i-1];
				pref[i]=max(pref[i],1LL);
			}
			for(ll i=n;i>0;i--)
			{
				
				if(s[i-1]=='o')
				{
					suff[i]=max(suff[i+1],suff[i]);
					if((i+k+1)<=n)
					{
						suff[i]=max(suff[i],suff[i+k+1]+1);
					}
				}
				else
					suff[i]=suff[i+1];
				suff[i]=max(suff[i],1LL);
			}
			for(ll i=1;i<=n;i++)
			{
				ll val1=0,val2=0;
				if((i-k-1)>=0)
					val1=pref[i-k-1];
				if((i+k+1)<=n)
					val2=suff[i+k+1];
				if(s[i-1]=='o')
				{
					if((pref[i-1]+suff[i+1])<c)
					{
						if((val1+val2+1)>=c)
							cout<<i<<endl;
					}
				}
			}
		}
