#include<bits/stdc++.h>
using namespace std;
#define int long long
#define CHAL_BC_APNE_BAAP_KO_MAT_SIKHA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define se second
#define mod 1000000007
int vis[200005];
vector<int> v[200005];
int k;
int n;
int c=1;
int bfs(int node){
	queue<pair<int,int> > q;
	q.push({node,1});
	vis[node]=1;
	int ans=c;
	ans=(ans*k)%mod;
	int level=1;
	while(!q.empty()){
		int node=q.front().fr;
		int minus=q.front().se;
		q.pop();
		int cnt=0;
		//cout<<ans<<endl;
		for(int i=0;i<v[node].size();i++){
			if(!vis[v[node][i]]){
				q.push({v[node][i],minus+1});
				vis[v[node][i]]=1;
				ans=(ans*(max(k-2,k-minus)-cnt))%mod;
				cnt++;
			}
		}
	}
	return ans;
}
signed main()
{
	CHAL_BC_APNE_BAAP_KO_MAT_SIKHA;		
	//int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	cout<<bfs(1);
}
