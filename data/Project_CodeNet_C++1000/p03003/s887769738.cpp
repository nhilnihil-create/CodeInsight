			#include <bits/stdc++.h>
			using namespace std;
			#define ll long long
			#define INF 100000000LL
			#define mod 1000000007
			#define pll pair<long,long>
			#define se second
			#define fi first
			#define pb push_back
			#include <ext/pb_ds/assoc_container.hpp>
			#include <ext/pb_ds/tree_policy.hpp>
			using namespace __gnu_pbds;

			typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
			typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update>pllordered_set;
			
			ll cache[3000][3000];
			vector<ll> v1;
			vector<ll> v2;
			
			ll dp(ll i,ll j)
			{
				if(i<0 || j<0)
					return 0;
				if(cache[i][j]!=-1)	
					return cache[i][j];
				
				ll ans=dp(i-1,j)+dp(i,j-1);
				ans%=mod;
				ans=(ans-dp(i-1,j-1)+mod)%mod;
				if(v1[i]==v2[j])
				{
					ans+=1+dp(i-1,j-1);
					ans%=mod;
				}
				return cache[i][j]=ans;
			}
			
			int main()
			{
				ll n,m;
				cin>>n>>m;
				v1.resize(n);
				v2.resize(m);
				for(ll i=0;i<n;i++)
				{
					cin>>v1[i];
				}
				for(ll i=0;i<m;i++)
				{
					cin>>v2[i];
				}
				for(ll i=0;i<=n;i++)
				{
					for(ll j=0;j<=m;j++)
						cache[i][j]=-1;
				}
				cout<<dp(n-1,m-1)+1;
				
						
			}
