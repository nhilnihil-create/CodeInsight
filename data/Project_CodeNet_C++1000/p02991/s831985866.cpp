#include <bits/stdc++.h>
using namespace std;
#define ll int
#define INF 100000000000
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


ll vis[100050][3];
vector<ll> g1[100050];

int main()
{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);
			ll n,m;
			cin>>n>>m;
			for(ll i=0;i<m;i++)
			{
				ll u,v;
				cin>>u>>v;
				g1[u].pb(v);
			}
			ll s,t;
			cin>>s>>t;
			queue<pll> q;
			q.push({s,0});
			memset(vis,-1,sizeof(vis));
			vis[s][0]=0;
			
			
			while(!q.empty())
			{
				pll node=q.front();
				q.pop();
				//cout<<node.fi<<" "<<vis[node.fi][node.se]<<endl;
				for(auto i:g1[node.fi])
				{
					
					if(vis[i][(node.se+1)%3]==-1)
						{
							vis[i][(node.se+1)%3]=vis[node.fi][node.se]+1;
							q.push({i,(node.se+1)%3});
						
						}
				}
			}
			//cout<<vis[t][0]<<endl;
			if(vis[t][0]!=-1)
				cout<<vis[t][0]/3;
			else
				cout<<-1;
			
}
